
using UnityEngine;
using System.Collections;
using System.IO.Ports;

public class read_ardunio : MonoBehaviour
{
    SerialPort sp = new SerialPort("COM2", 9600);

    void Start()
    {
        sp.Open();
        sp.ReadTimeout = 1;
    }

    void Update()
    {
        try
        {
            print(sp.ReadLine());
        }
        catch (System.Exception)
        {
            print("Exception occured");
        }
    }
}


/*using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.IO.Ports;
using System;

public class read_ardunio : MonoBehaviour {

    SerialPort mySerialPort = new SerialPort("COM2");
    public int received;
    // Use this for initialization
    void Start () {
       

        mySerialPort.BaudRate = 9600;
        mySerialPort.Parity = Parity.None;
        mySerialPort.StopBits = StopBits.One;
        mySerialPort.DataBits = 8;
        mySerialPort.Handshake = Handshake.None;
        mySerialPort.RtsEnable = true;

        mySerialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

        mySerialPort.Open();

        Console.WriteLine("Press any key to continue...");
        Console.WriteLine();
        Console.ReadKey();
        mySerialPort.Close();
        // StartCoroutine(REad());
    }

    // Update is called once per frame
    private void Update()
    {
        DataReceivedHandler();
    }
    private static void DataReceivedHandler(
                object sender,
                SerialDataReceivedEventArgs e)
    {
        SerialPort sp = (SerialPort)sender;
        string indata = sp.ReadExisting();
        Console.WriteLine("Data Received:");
        Console.Write(indata);
    }
/*
    public  IEnumerator REad()
    {
        yield return null;
        while (true)
        {try
            {
                if (sp.IsOpen)
                {
                    received = sp.ReadChar();

                }
                else
                    sp.Open();
                if (received == 65)
                {
                    break;
                }
            }

            catch (Exception ex)
            {
                // This could be thrown if we close the port whilst the thread 
                // is reading data. So check if this is the case!
                if (sp.IsOpen)
                {
                    // Something has gone wrong!
                    Debug.Log(ex.Message.ToString());

                }
                else
                    print("Port closed");
            }
        }
       
    }
}
*/
