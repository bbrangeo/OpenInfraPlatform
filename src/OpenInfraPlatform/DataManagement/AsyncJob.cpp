/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Fabian Schöttl <fabian.schoettl@tum.de> (https://www.cms.bgu.tum.de/en/)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "AsyncJob.h"

OpenInfraPlatform::AsyncJob& OpenInfraPlatform::AsyncJob::getInstance()
{
	static AsyncJob job;
	return job;
}

bool OpenInfraPlatform::AsyncJob::updateStatus(float progress, const std::string& message)
{
	if (std::this_thread::get_id() != thread_.get_id())
		return true;

	statusMutex_.lock();
	status_.progress_ = progress;
	status_.message_ = message;
	statusMutex_.unlock();

	return !cancel_;
}

void OpenInfraPlatform::AsyncJob::cancelJob()
{
	if (running_)
		cancel_ = true;
}

void OpenInfraPlatform::AsyncJob::run()
{
	running_ = true;
	job_();
	running_ = false;
	Q_EMIT finished();
}

void OpenInfraPlatform::AsyncJob::checkThread()
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

bool OpenInfraPlatform::AsyncJob::updateStatus(const std::string& message)
{
	if (std::this_thread::get_id() != thread_.get_id())
		return true;

	statusMutex_.lock();
	status_.message_ = message;
	statusMutex_.unlock();

	return !cancel_;
}

bool OpenInfraPlatform::AsyncJob::updateStatus(float progress)
{
	if (std::this_thread::get_id() != thread_.get_id())
		return true;

	statusMutex_.lock();
	status_.progress_ = progress;
	statusMutex_.unlock();

	return !cancel_;
}
