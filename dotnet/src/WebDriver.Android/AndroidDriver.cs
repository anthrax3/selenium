﻿using System;
using System.Collections.Generic;
using System.Text;
using OpenQA.Selenium.Remote;

namespace OpenQA.Selenium.Android
{
    /// <summary>
    /// Provides a mechanism to write tests against an Android device
    /// </summary>
    /// <example>
    /// <code>
    /// [TestFixture]
    /// public class Testing
    /// {
    ///     private IWebDriver driver;
    ///     <para></para>
    ///     [SetUp]
    ///     public void SetUp()
    ///     {
    ///         driver = new AndroidDriver();
    ///     }
    ///     <para></para>
    ///     [Test]
    ///     public void TestGoogle()
    ///     {
    ///         driver.Navigate().GoToUrl("http://www.google.co.uk");
    ///         /*
    ///         *   Rest of the test
    ///         */
    ///     }
    ///     <para></para>
    ///     [TearDown]
    ///     public void TearDown()
    ///     {
    ///         driver.Quit();
    ///     } 
    /// }
    /// </code>
    /// </example>
    /// <remarks>
    /// Using the Android driver requires the Android device or emulator
    /// to be running, and the WebDriver application be active on the device.
    /// </remarks>
    public class AndroidDriver : RemoteWebDriver, ITakesScreenshot
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AndroidDriver"/> class.
        /// </summary>
        public AndroidDriver() :
            this(GetDefaultUrl())
        {
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AndroidDriver"/> class,
        /// communicating with the device at a specific URL.
        /// </summary>
        /// <param name="remoteAddress">The URL of the WebDriver application on the Android device.</param>
        public AndroidDriver(string remoteAddress) :
            this(new Uri(remoteAddress))
        {
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AndroidDriver"/> class,
        /// communicating with the device at a specific URL.
        /// </summary>
        /// <param name="remoteAddress">The URL of the WebDriver application on the Android device.</param>
        public AndroidDriver(Uri remoteAddress) :
            base(remoteAddress, GetAndroidCapabilities())
        {
        }

        #region ITakesScreenshot Members
        /// <summary>
        /// Gets a <see cref="Screenshot"/> object representing the image of the page on the screen.
        /// </summary>
        /// <returns>A <see cref="Screenshot"/> object containing the image.</returns>
        public Screenshot GetScreenshot()
        {
            // Get the screenshot as base64.
            Response screenshotResponse = Execute(DriverCommand.Screenshot, null);
            string base64 = screenshotResponse.Value.ToString();

            // ... and convert it.
            return new Screenshot(base64);
        }
        #endregion

        private static Uri GetDefaultUrl()
        {
            return new Uri("http://localhost:8080/hub");
        }

        private static DesiredCapabilities GetAndroidCapabilities()
        {
            DesiredCapabilities caps = DesiredCapabilities.Android();
            caps.SetCapability(CapabilityType.TakesScreenshot, true);
            caps.SetCapability(CapabilityType.Rotatable, true);
            ////caps.SetCapability(CapabilityType.SUPPORTS_BROWSER_CONNECTION, true);
            return caps;
        }
    }
}