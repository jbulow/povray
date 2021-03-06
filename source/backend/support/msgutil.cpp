/*******************************************************************************
 * msgutil.cpp
 *
 * This module implements misc utility functions.
 *
 * ---------------------------------------------------------------------------
 * Persistence of Vision Ray Tracer ('POV-Ray') version 3.7.
 * Copyright 1991-2013 Persistence of Vision Raytracer Pty. Ltd.
 *
 * POV-Ray is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * POV-Ray is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ---------------------------------------------------------------------------
 * POV-Ray is based on the popular DKB raytracer version 2.12.
 * DKBTrace was originally written by David K. Buck.
 * DKBTrace Ver 2.0-2.12 were written by David K. Buck & Aaron A. Collins.
 * ---------------------------------------------------------------------------
 * $File: //depot/public/povray/3.x/source/backend/support/msgutil.cpp $
 * $Revision: #1 $
 * $Change: 6069 $
 * $DateTime: 2013/11/06 11:59:40 $
 * $Author: chrisc $
 *******************************************************************************/

#include <ctype.h>
#include <stdarg.h>

// frame.h must always be the first POV file included (pulls in platform config)
#include "backend/frame.h"
#include "backend/support/msgutil.h"

#include "povrayold.h" // TODO

// this must be the last file included
#include "base/povdebug.h"

namespace pov
{

/*****************************************************************************
*
* FUNCTION
*   POVMSUtil_SetFormatString
*   
* DESCRIPTION
*   Stores a string with format information in the given attribute.
*
* CHANGES
*   -
*
******************************************************************************/

int POVMSUtil_SetFormatString(POVMSObjectPtr object, POVMSType key, const char *format, ...) // Note: Strings may not contain \0 characters codes!
{
	va_list marker;
	char buffer[1024];

	va_start(marker, format);
	vsprintf(buffer, format, marker);
	va_end(marker);

	return POVMSUtil_SetString(object, key, buffer);
}

}
