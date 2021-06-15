using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.IO.Ports;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Input;

namespace EasyMouse
{
    public partial class MainWindow : Window
    {
        [DllImport("user32.dll")] static extern int SetCursorPos(int x, int y);
        [DllImport("user32.dll")] static extern bool GetCursorPos(ref MousePoint lpPoint);
        [DllImport("user32.dll")] static extern void mouse_event(uint dwFlags, uint dx, uint dy, uint dwData, int dwExtraInfo);
        const uint LBUTTONDOWN = 0x0002;
        const uint LBUTTONUP = 0x0004;

        private SerialPort serial = new();
        int a = 0;

        int pointX;
        int pointY;
        bool isClick;

        public struct MousePoint
        {
            public int x;
            public int y;
        };
        MousePoint mouse = new();

        public MainWindow()
        {
            InitializeComponent();
        }

        void EventDataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = sender as SerialPort;
            if (sp == null)
            {
                return;
            }

            char c;
            List<char> buf = new();
            while ((c = (char)serial.ReadByte()) != '/')
            {
                if (c != '\0')
                    buf.Add(c);
            }
            char[] arr = buf.ToArray();
            StringBuilder sb = new();
            sb.Append(arr, 0, arr.Length);

            try
            {
                pointX = Convert.ToInt32(sb.ToString().Split('.')[0]);
                pointY = Convert.ToInt32(sb.ToString().Split('.')[1].Split('.')[0]);
                isClick = !Convert.ToBoolean(Convert.ToInt32(sb.ToString().Split('.')[2].Split('.')[0]));
            }
            catch { }

            GetCursorPos(ref mouse);
            SetCursorPos(mouse.x + ((486 - pointX) / 50), mouse.y + ((494 - pointY) / 50));

            if (isClick) mouse_event(LBUTTONDOWN, 0, 0, 0, 0);
            else mouse_event(LBUTTONUP, 0, 0, 0, 0);

            Debug.WriteLine(isClick);
            Debug.WriteLine(string.Format("x: {0} y:{0} c:{0}", pointX, pointY, isClick));
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            try
            {
                if (null != serial)
                {
                    serial = new SerialPort();
                    serial.PortName = "COM3";   // 컴포트명
                    serial.BaudRate = 9600;   // 보레이트

                    serial.DataReceived += new SerialDataReceivedEventHandler(EventDataReceived);
                    serial.Open();
                }
            }
            catch (Exception ex)
            {
            }
        }
    }
}
