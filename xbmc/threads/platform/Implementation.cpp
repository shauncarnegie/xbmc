/*
 *      Copyright (C) 2005-2011 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "threads/platform/platform.select"

#ifdef USE_BOOST_LOCKING
#define LOCKING_IMPL_SET
// There is no boost implementation cpp file
#endif

#ifdef USE_PTHREADS_LOCKING
#ifdef LOCKING_IMPL_SET
#error "Cannot set two USE_*_LOCKING flags"
#endif
#define LOCKING_IMPL_SET
#include "threads/platform/pthreads/Implementation.cpp"
#endif

#ifndef LOCKING_IMPL_SET
#error "No platform specified for the implemenation code."
#endif

#undef LOCKING_IMPL_SET
