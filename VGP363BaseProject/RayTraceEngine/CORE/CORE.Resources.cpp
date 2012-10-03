// CORE.Resources.cpp
///////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

#include "..\GameCore.h"

namespace GameCore {
	
	///////////////////////////////////////////////////////////////////////////
	// Resource Information

	//int *Resources::m_ObjectCells_64x64 = NULL;

	void ResourceLoader::_LoadResources() {
            //_LoadImage(&Resources::m_ObjectCells_64x64, GameResources::Properties::Resources::ObjectCells_64x64);
	}

	/////////////////////////////////////////////////////////////////////////////////////////
	// Utility Functions

	BitmapData^ _GetImageData(Bitmap^ bmp) {
		Rectangle^ rect = gcnew Rectangle(0, 0, bmp->Width, bmp->Height);
		BitmapData^ bmpData = bmp->LockBits(
			*rect, ImageLockMode::ReadWrite, PixelFormat::Format32bppArgb
		);
		return bmpData;
	}

	void _LoadImage(int** pDest, IntPtr pSurface, int length) {
		int *pSrc = (int*)pSurface.ToPointer();
		*pDest = new int[length];
		memcpy(*pDest, pSrc, length);
	}

	void _LoadImage(int** pDest, Bitmap^ bmp) {
        BitmapData^ bmpData = _GetImageData(bmp);
        _LoadImage(pDest, bmpData->Scan0, bmpData->Stride * bmpData->Height);
        bmp->UnlockBits(bmpData);
	}

}