#pragma once
#include <godmode.engine/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

// class NxMemoryWriteBuffer : public NxStream { $
//         NxMemoryWriteBuffer();
//         virtual	destructor$(NxMemoryWriteBuffer();
//         void			clear();
//         virtual		NxU8			readByte()								const	{ NX_ASSERT(0);	return 0;	}
//         virtual		NxU16			readWord()								const	{ NX_ASSERT(0);	return 0;	}
//         virtual		NxU32			readDword()								const	{ NX_ASSERT(0);	return 0;	}
//         virtual		float			readFloat()								const	{ NX_ASSERT(0);	return 0.0f;}
//         virtual		double			readDouble()							const	{ NX_ASSERT(0);	return 0.0;	}
//         virtual		void			readBuffer(void* buffer, NxU32 size)	const	{ NX_ASSERT(0);				}
//         virtual		NxStream&		storeByte(NxU8 b);
//         virtual		NxStream&		storeWord(NxU16 w);
//         virtual		NxStream&		storeDword(NxU32 d);
//         virtual		NxStream&		storeFloat(NxReal f);
//         virtual		NxStream&		storeDouble(NxF64 f);
//         virtual		NxStream&		storeBuffer(const void* buffer, NxU32 size);
//         NxU32			currentSize;
//         NxU32			maxSize;
//         NxU8*			data;
// };