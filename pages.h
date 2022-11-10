/*
 * Copyright (C) 2019 Ricardo Leite. All rights reserved.
 * Licenced under the MIT licence. See COPYING file in the project root for
 * details.
 */

#ifndef __PAGES_H
#define __PAGES_H

#include <cinttypes>
#include <cstddef>

#include "lrmalloc.h"

// return page address for page containing a
#define PAGE_ADDR2BASE(a) ((void*)((uintptr)(a) & ~PAGE_MASK))

// returns a set of continous pages, totaling to size bytes
void* PageAlloc(size_t size);
// explictely allow overcommiting
// used for array-based page map
void* PageAllocOvercommit(size_t size);
// free a set of continous pages, totaling to size bytes
void PageFree(void* ptr, size_t size);
// reallocate memory in the virtual adress freed by PageFreePersistent
void PageAllocPersistent(void* ptr, size_t size);
// same as PageFree but keep the virtual adresses valid for read
void PageFreePersistent(void* ptr, size_t size);
// init fd for page remaps
void InitShmFd(void);

#endif // __PAGES_H
