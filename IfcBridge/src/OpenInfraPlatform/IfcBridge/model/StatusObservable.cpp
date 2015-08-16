/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "StatusObservable.h"

namespace OpenInfraPlatform
{
    namespace IfcBridge
    {

        StatusObservable::StatusObservable()
        {
            unsetProgressCallBack();
            unsetProgressTextCallBack();
            unsetMessageCallBack();
            unsetErrorCallBack();
        }

        StatusObservable::~StatusObservable()
        {
        }

        void StatusObservable::setProgressCallBack( void* obj_ptr, void (*func)(void*, double) )
        {
            m_obj_call_on_progress = obj_ptr;
            m_func_call_on_progress = func;
        }
        void StatusObservable::unsetProgressCallBack()
        {
            m_obj_call_on_progress = 0;
            m_func_call_on_progress = 0;
        }

        void StatusObservable::progressCallback( double progress_value )
        {
            if( m_func_call_on_progress )
            {
                if( m_obj_call_on_progress )
                {
                    m_func_call_on_progress( m_obj_call_on_progress, progress_value );
                }
            }
        }

        void StatusObservable::progressTextCallback( const std::string& str )
        {
            if( m_func_call_on_progress_text )
            {
                if( m_obj_call_on_progress_text )
                {
                    m_func_call_on_progress_text( m_obj_call_on_progress_text, str );
                }
            }
        }

        void StatusObservable::setProgressTextCallBack( void* obj_ptr, void (*func)(void*, const std::string& message) )
        {
            m_obj_call_on_progress_text = obj_ptr;
            m_func_call_on_progress_text = func;
        }

        void StatusObservable::unsetProgressTextCallBack()
        {
            m_obj_call_on_progress_text = 0;
            m_func_call_on_progress_text = 0;
        }

		// message callback
        void StatusObservable::setMessageCallBack( void* obj_ptr, void (*func)(void*, const std::string&) )
        {
            m_obj_call_on_message = obj_ptr;
            m_func_call_on_message = func;
        }

        void StatusObservable::unsetMessageCallBack()
        {
            m_obj_call_on_message = 0;
            m_func_call_on_message = 0;
        }

        void StatusObservable::messageCallback( const std::string& str )
        {
            if( m_func_call_on_message )
            {
                if( m_obj_call_on_message )
                {
                    m_func_call_on_message( m_obj_call_on_message, str );
                }
            }
        }

		// error callback
        void StatusObservable::setErrorCallBack( void* obj_ptr, void (*func)(void*, const std::string&) )
        {
            m_obj_call_on_error = obj_ptr;
            m_func_call_on_error = func;
        }

        void StatusObservable::unsetErrorCallBack()
        {
            m_obj_call_on_error = 0;
            m_func_call_on_error = 0;
        }

        void StatusObservable::errorCallback( const std::string& str )
        {
            if( m_func_call_on_error )
            {
                if( m_obj_call_on_error )
                {
                    m_func_call_on_error( m_obj_call_on_error, str );
                }
            }
        }
    } // end namespace IfcBridge
} // end namespace OpenInfraPlatform