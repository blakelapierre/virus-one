// virus_macros.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#pragma once

#ifndef null
#define null 0
#endif // null

#ifndef DELETE_OBJECT
#define DELETE_OBJECT(x) if (x) { delete x; x = null; }
#endif // DELETE_OBJECT

#ifndef DELETE_OBJECT_ARRAY
#define DELETE_OBJECT_ARRAY(x) if (x) { delete[] x; x = null; }
#endif // DELETE_OBJECT_ARRAY

#ifndef FREE_OBJECT
#define FREE_OBJECT(x) if (x) { ::free(x); x = null; }
#endif // FREE_OBJECT
