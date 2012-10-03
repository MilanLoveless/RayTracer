using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace NixRayViewer
{
    public partial class MainForm : Form
    {
        private System.Drawing.Bitmap _bmpPrimarySurface = null;
        private GameCore.GameClass _GameClass = null;
        private System.Windows.Forms.Timer _Timer1 = null;
        private System.Threading.Thread _thread = null;

        public MainForm()
        {
            InitializeComponent();
            _InitializeSystem();
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            // Abort the background thread when the user
            // closes the application.
            _thread.Abort();
        }

        void _InitializeSystem()
        {
            //////////////////////////////////////////////////////////////////////////
            // Load resources
            //GameCore.ResourceLoader._LoadResources();
            //////////////////////////////////////////////////////////////////////////

            _bmpPrimarySurface = new Bitmap(
                _pictureBox.Width, _pictureBox.Height,
                System.Drawing.Imaging.PixelFormat.Format32bppArgb
            );

            _GameClass = new GameCore.GameClass();

            //////////////////////////////////////////////////////////////////////////
            // Background Drawing Thread: We will begin drawing stuff in the background
            ThreadStart ts = new ThreadStart(_OnBeginBackgroundDrawing);
            _thread = new System.Threading.Thread(ts);
            _thread.Start();

            //////////////////////////////////////////////////////////////////////////
            // Frame timer: We will periodically draw what is currently rendered
            _Timer1 = new System.Windows.Forms.Timer();
            _Timer1.Tick += new EventHandler(_OnFrameTimer);
            _Timer1.Interval = 100;
            _Timer1.Start();
            // Call it once so we don't have to wait 1 second
            //_OnFrame(_bmpPrimarySurface);
        }

        void _OnBeginBackgroundDrawing()
        {
            _OnBeginBackgroundDrawing(_bmpPrimarySurface);
        }

        void _OnFrameTimer(object sender, EventArgs e)
        {
            _OnFrame(_bmpPrimarySurface);
        }

        private void _LockImage(Bitmap bmp, out BitmapData bmpData, out IntPtr ptr)
        {
            Rectangle rect = new Rectangle(0, 0, bmp.Width, bmp.Height);
            bmpData = bmp.LockBits(
                rect, System.Drawing.Imaging.ImageLockMode.ReadWrite, bmp.PixelFormat
            );
            ptr = bmpData.Scan0;
        }

        private void _UnlockImage(Bitmap bmp, BitmapData bmpData)
        {
            bmp.UnlockBits(bmpData);
        }

        private void _OnBeginBackgroundDrawing(Bitmap bmp)
        {
            BitmapData bmpData; IntPtr ptr;
            int nWidth, nHeight, nRowPadding;
            lock (_bmpPrimarySurface)
            {
                _LockImage(bmp, out bmpData, out ptr);
                nWidth = bmp.Width;
                nHeight = bmp.Height;
                nRowPadding = bmpData.Stride / 4 - bmp.Width;
                _UnlockImage(bmp, bmpData);
            }

            _GameClass._OnBeginBackgroundDrawing(nWidth, nHeight, nRowPadding);
        }

        private void _OnFrame(Bitmap bmp)
        {
            lock (_bmpPrimarySurface)
            {
                BitmapData bmpData; IntPtr ptr;
                _LockImage(bmp, out bmpData, out ptr);
                int nWidth = bmp.Width;
                int nHeight = bmp.Height;
                int nRowPadding = bmpData.Stride / 4 - bmp.Width;

                _GameClass._OnFrame(nWidth, nHeight, nRowPadding, ptr);
                _UnlockImage(bmp, bmpData);

                _pictureBox.Image = _bmpPrimarySurface;
            }
        }
    }
}
