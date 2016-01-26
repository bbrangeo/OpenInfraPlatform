/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Fabian Schöttl <fabian.schoettl@tum.de> (https://www.cms.bgu.tum.de/en/)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once

#include <boost/signals2.hpp>
#include <QTimer>
#include <QObject>

#include <functional>
#include <deque>
#include <thread>
#include <mutex>

namespace OpenInfraPlatform
{
	class AsyncJob : public QObject
	{
		Q_OBJECT;

		struct AsyncStatus
		{
			AsyncStatus() :
				progress_(-1), message_("")
			{}

			AsyncStatus(float progress, const std::string& message) :
				progress_(progress), message_(message)
			{}


			float		progress_;
			std::string message_;
		};

	public:
		static AsyncJob& getInstance();

		template<typename Function, typename ... Args>
		int startJob(Function&& functionPtr, const Args& ... args)
		{
			if (running_)
				return -1;

			job_ = std::bind(functionPtr, args...);			// Caution: references will be treated as values, use std::ref() to create reference wrappers when calling startJob()
			jobID_++;
			first_ = true;
			cancel_ = running_ = false;

			status_ = AsyncStatus();

			jobStarting();
			thread_ = std::thread(&AsyncJob::run, this);
			refreshTimer_->start();

			return jobID_;
		}

		bool updateStatus(float progress, const std::string& message);

		bool updateStatus(float progress);

		bool updateStatus(const std::string& message);

		void cancelJob();

		boost::signals2::signal<void()> jobStarting;
		boost::signals2::signal<void(int jobID)> jobStarted;
		boost::signals2::signal<void(int jobID, float progress, const std::string& message)> jobRunning;
		boost::signals2::signal<void(int jobID, bool completed)> jobFinishing;
		boost::signals2::signal<void(int jobID, bool completed)> jobFinished;

		Q_SIGNAL void finished();
	
	private:
		AsyncJob()
		{
			jobID_ = 0;
			running_ = cancel_ = false;

			refreshTimer_ = new QTimer();
			refreshTimer_->setInterval(200);
			connect(refreshTimer_, SIGNAL(timeout()), this, SLOT(checkThread()));
		}

		void run();
	
	private Q_SLOTS:
		void checkThread();
		
	private:
		std::function<void()> job_;
		int jobID_;
		
		std::thread thread_;
		bool running_, cancel_, first_;

		std::mutex statusMutex_;
		AsyncStatus status_;

		QTimer*	refreshTimer_;
	};
}
