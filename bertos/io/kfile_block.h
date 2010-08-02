/**
 * \file
 * <!--
 * This file is part of BeRTOS.
 *
 * Bertos is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 *
 * Copyright 2010 Develer S.r.l. (http://www.develer.com/)
 *
 * -->
 *
 * \brief KFile interface over a KBlock.
 *
 * With this module, you can access a KBlock device
 * with the handy KFile interface.
 * In order to achieve this, the block device must support partial block write.
 */

#ifndef IO_KFILE_BLOCK_H
#define IO_KFILE_BLOCK_H

#include <cfg/compiler.h>
#include <io/kblock.h>
#include <io/kfile.h>

/**
 * KFileBlock context.
 */
typedef struct KFileBlock
{
	KFile fd;  ///< KFile context
	KBlock *b; ///< KBlock device
} KFileBlock;

/**
 * Init a KFile over KBlock.
 * After this you can access your KBlock device with a handy KFile interface.
 *
 * \note The block device must support partial block write in order support
 *       random write access.
 *
 * \param fb KFileBlock context.
 * \param b  block device to be accessed with a KFile interface.
 */
void kfileblock_init(KFileBlock *fb, KBlock *b);

#endif /* IO_KFILE_KBLOCK_H */
