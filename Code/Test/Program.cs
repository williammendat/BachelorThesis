using System;
using Iot.Device.Common;
using Iot.Device.SenseHat;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            using SenseHat sh = new SenseHat();

            var defaultSeaLevelPressure = WeatherHelper.MeanSeaLevel;

            var tempValue = sh.Temperature.ToString();
            var temp2Value = sh.Temperature2;
            var preValue = sh.Pressure;
            var humValue = sh.Humidity;
            var accValue = sh.Acceleration;
            var angValue = sh.AngularRate;
            var magValue = sh.MagneticInduction;
            var altValue = WeatherHelper.CalculateAltitude(preValue, defaultSeaLevelPressure, tempValue);

        }
    }
}