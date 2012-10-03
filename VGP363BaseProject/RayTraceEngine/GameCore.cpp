// GameCore.cpp
////////////////////////////////////////////////////////////

#include "GameCore.h"

namespace GameCore {

	int *g_pDisplayBuffer = NULL;	// Buffer ready for display
	int *g_pBackBuffer = NULL;		// Buffer being rendered into

	void GameClass::_OnBeginBackgroundDrawing(int nWidth, int nHeight, int nRowPadding) {

		// Load level /////////////////////////////////////////////

		g_pDisplayBuffer = new int[(nWidth+nRowPadding)*nHeight];
		g_pBackBuffer = new int[(nWidth+nRowPadding)*nHeight];

		///////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////
		// Diagnostics 1: Clear background to verify base project
		//for(int n = 0; n < (nWidth+nRowPadding)*nHeight; n++) {
		//	g_pDisplayBuffer[n] = 0xFF000000;
		//}

		while(true) {

			//////////////////////////////////////////////////////////////////////
			// Render image into display buffer
			
			// *** RENDER YOUR RAY TRACE OBJECT HERE ***

			//////////////////////////////////////////////////////////////////////

			// Copy rendered image into display buffer
			for(int n = 0; n < (nWidth+nRowPadding)*nHeight; n++) {
				g_pDisplayBuffer[n] = g_pBackBuffer[n];
			}

		}

		/////////////////////////////////////////////////////
		// Diagnostics 1: Verify the basic infrastructure
		// --------------------------------------------------
		//if(n % 1000 == 0) {
		//	System::Threading::Thread::Sleep(1);
		//}
		/////////////////////////////////////////////////////
	}

	void GameClass::_OnFrame(int nWidth, int nHeight, int nRowPadding, IntPtr pSurface) {
		int* video = (int*)pSurface.ToPointer();

		// Draw whatever is in the background drawing buffer
		if(g_pDisplayBuffer != NULL) {
			// Bit block transfer back buffer to video screen (using for-loop)
			for(int n = 0; n < (nWidth+nRowPadding)*nHeight; n++) {
				video[n] = g_pDisplayBuffer[n];
			}
		}

	}

}