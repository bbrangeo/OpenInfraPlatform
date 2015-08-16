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
		static AsyncJob& getInstance()
		{
			static AsyncJob job;
			return job;
		}

		template<typename Function, typename ... Args>
		int startJob(Function&& functionPtr, Args& ... args)
		{
			if (running_)
				return -1;

			job_ = std::bind(functionPtr, args...);			// Caution: references will be treated as values, use std::ref() to create reference wrappers when calling startJob()
			jobID_++;
			first_ = true;
			cancel_ = running_ = false;

			status_ = AsyncStatus();

			thread_ = std::thread(&AsyncJob::run, this);
			refreshTimer_->start();

			return jobID_;
		}

		bool updateStatus(float progress, const std::string& message)
		{
			if (std::this_thread::get_id() != thread_.get_id())
				return true;

			statusMutex_.lock();
			status_.progress_ = progress;
			status_.message_ = message;
			statusMutex_.unlock();

			return !cancel_;
		}

		bool updateStatus(float progress)
		{
			if (std::this_thread::get_id() != thread_.get_id())
				return true;

			statusMutex_.lock();
			status_.progress_ = progress;
			statusMutex_.unlock();

			return !cancel_;
		}

		bool updateStatus(const std::string& message)
		{
			if (std::this_thread::get_id() != thread_.get_id())
				return true;

			statusMutex_.lock();
			status_.message_ = message;
			statusMutex_.unlock();

			return !cancel_;
		}

		void cancelJob()
		{
			if (running_)
				cancel_ = true;
		}

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

		void run()
		{
			running_ = true;
			job_();
			running_ = false;
			Q_EMIT finished();
		}

		
	
	private Q_SLOTS:
		void checkThread()
		{
			if (first_)
			{
				jobStarted(jobID_);
				first_ = false;
			}
			if (!running_)
			{
				thread_.join();
				refreshTimer_->stop();
				jobFinishing(jobID_, !cancel_);
				jobFinished(jobID_, !cancel_);
			}
			else
			{
				statusMutex_.lock();
				jobRunning(jobID_, status_.progress_, status_.message_);
				statusMutex_.unlock();
			}
		}
		

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
