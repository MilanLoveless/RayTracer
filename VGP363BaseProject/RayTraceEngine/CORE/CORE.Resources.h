// CORE.Resources.h
///////////////////////////////////////////////////////

#ifndef __CORE_RESOURCES_H_
#define __CORE_RESOURCES_H_

#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Windows::Forms;

namespace GameCore {

	///////////////////////////////////////////////////////////////////////////
	// Resource Information

	public class Resources {
	public:
		static int *m_ObjectCells_64x64;
		static int *m_CharacterCells_64x64;
        static int *m_YouWinScreen_573x431;
        static int *m_YouLoseScreen_573x431;
		static int *m_TitleMessage_PleaseWait_104x21;
		static int *m_TitleScreenBackground_574x432;
		static int *m_TitleScreenCaption_574x432;
		static int *m_SlidingDoorBottom_575x433;
		static int *m_SlidingDoorTop_575x433;
		static int *m_MainMenuBackground_573x431;
        static int *m_Menu_Continue_Hover_211x63;
        static int *m_Menu_Continue_Idle_211x63;
        static int *m_Menu_NewGame_Hover_211x63;
        static int *m_Menu_NewGame_Idle_211x63;
        static int *m_Menu_Options_Hover_211x63;
        static int *m_Menu_Options_Idle_211x63;
        static int *m_Menu_Quit_Hover_211x63;
        static int *m_Menu_Quit_Idle_211x63;
		
		static int *m_CubeTexture_256x256;
		static int *m_CubeBumpMap_256x256;

		static int *m_AegisCraft_800x600;
		static int *m_AegisCraft_FlightStick_85x83;
		static int *m_AegisCraft_Throttle_Idle_56x23;
		static int *m_AegisCraft_Throttle_Hover_56x23;
		static int *m_AegisCraft_WeaponButton_Hover_46x41;
		static int *m_AegisCraft_ConsoleButton_Hover_25x25;
	};

	public ref class ResourceLoader {
	public:
		static void _LoadResources();
	};

	/////////////////////////////////////////////////////////////////////////
	// Utility Functions

	BitmapData^ _GetImageData(Bitmap^ bmp);
	void _LoadImage(int** pDest, IntPtr pSurface, int length);
	void _LoadImage(int** pDest, Bitmap^ bmp);
}

#endif