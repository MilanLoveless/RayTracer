// GameCore.h
///////////////////////////////////////////////////////////////////

#ifndef __GAME_CORE_H_
#define __GAME_CORE_H_

#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "CORE\CORE.Animation.h"
#include "CORE\CORE.Collection.h"
#include "CORE\CORE.Collision.h"
#include "CORE\CORE.Controller.h"
#include "CORE\CORE.Drawing.h"
#include "CORE\CORE.Keyboard.h"
#include "CORE\CORE.Math.h"
#include "CORE\CORE.Mouse.h"
#include "CORE\CORE.Resources.h"

#include "CORE\3D\CORE.Drawing.Primitives.h"
#include "CORE\3D\CORE.Matrix.h"
#include "CORE\3D\CORE.Quaternion.h"
#include "3D_OBJECTS\Camera.h"

using namespace System;

namespace GameCore {

	public ref class GameClass {
	public:

		void _OnBeginBackgroundDrawing(int nWidth, int nHeight, int nRowPadding);
		void _OnFrame(int nWidth, int nHeight, int nRowPadding, IntPtr pSurface);

	};

}

#endif