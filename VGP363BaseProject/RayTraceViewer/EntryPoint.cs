using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace NixRayViewer
{
    static class EntryPoint
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
    }
}
