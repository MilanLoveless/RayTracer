// CORE.Mouse.h
///////////////////////////////////////////////////////

#ifndef __CORE_MOUSE_H_
#define __CORE_MOUSE_H_

namespace GameCore {

	public ref class Mouse {
	public:

		static int m_X = 0;
		static int m_Y = 0;
		static bool m_bLeftButtonDown = false;

		static bool _CollisionCheck(int x1, int y1, int x2, int y2) {
			if(Mouse::m_X < x2 && Mouse::m_X >= x1) {
				if(Mouse::m_Y < y2 && Mouse::m_Y >= y1) {
					return true;
				}
			}
			return false;
		}

	};

}

#endif