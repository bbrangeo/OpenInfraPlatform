/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <sstream>

namespace OpenInfraPlatform
{
    namespace IfcRoad
    {
        class StatusObservable
        {
        public:
            StatusObservable();
            ~StatusObservable();
            virtual const char* className()
            {
                return "StatusObservable";
            }

            //! @brief read progress callback mechanism to update progress bar or similar
            void setProgressCallBack( void* obj_ptr, void (*func)(void*, double) );
            void unsetProgressCallBack();

            void setProgressTextCallBack( void* obj_ptr, void (*func)(void*, const std::string& message) );
            void unsetProgressTextCallBack();

            //! @brief message callback mechanism to show messages in gui
            void setMessageCallBack( void* obj_ptr, void (*func)(void*, const std::string& message) );
            void unsetMessageCallBack();

            //! @brief error callback mechanism to show errors in gui
            void setErrorCallBack( void* obj_ptr, void (*func)(void*, const std::string& message) );
            void unsetErrorCallBack();

        protected:
            // progress callback
            void* m_obj_call_on_progress;
            void (*m_func_call_on_progress)(void*, double);
            void progressCallback(double progress);

            void* m_obj_call_on_progress_text;
            void (*m_func_call_on_progress_text)(void*, const std::string& message);
            void progressTextCallback( const std::string& message );

            void* m_obj_call_on_message;
            void (*m_func_call_on_message)(void*, const std::string& message);
            void messageCallback( const std::string& message );

            void* m_obj_call_on_error;
            void (*m_func_call_on_error)(void*, const std::string& err);
            void errorCallback( const std::string& err );
        };
    } // end namespace IfcRoad
} // end namespace OpenInfraPlatform