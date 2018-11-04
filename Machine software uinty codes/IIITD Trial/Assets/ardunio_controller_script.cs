using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.IO.Ports;
using System;
using UnityEngine.UI;
using UnityEngine.SceneManagement;



public class ardunio_controller_script : MonoBehaviour {
    public GameObject Vinay;
    public GameObject Prescription;
    public bool Callable = true;
    public GameObject Srishtee;
    public GameObject animesh;
    public GameObject manoj;
    public bool write = true;
    public GameObject Fingerprint;
    public int i;
    public float timeleft = 5f;
    public bool verifyed = false;

    public Text NAME_TEXT;
    public Text USERID_TEXT;
    public Text AADHAR_NO_TEXT;
    public Text MEDICINES_TEXT;
    public Text Disease_TEXT;
    public GameObject Details_Panel;
    public String Received;
    public String[] NAMES = new string[3];
    public String[] userID = new string[3];
    public String[] aadhar = new string[3];
    public String[] Medicine = new string[3];
    public String[] Disease = new string[3];
    public bool writing= true;
    public bool reading= false;

    SerialPort sp = new SerialPort("COM1", 9600);
    public string a = null;

   
    // Use this for initialization
    void Start () {
        
        sp.Open();
        Details_Panel.SetActive(false);
        Fingerprint.SetActive(false);

    }
	
	// Update is called once per frame
	void Update () {
        if (Callable)
        {
            if (Vinay.GetComponent<MeshRenderer>().isVisible)
            {
                Prescription.SetActive(false);
                writeOnArdunio(2);
                SetTheText(0, 0, 0, 0, 0);
                Callable = false;

            }
            else if (Srishtee.GetComponent<MeshRenderer>().isVisible)
            {
                Prescription.SetActive(false);
                SetTheText(1, 1, 1, 1, 1);
                writeOnArdunio(1);
                Callable = false;
            }
            else if (animesh.GetComponent<MeshRenderer>().isVisible)
            {
                Prescription.SetActive(false);
                SetTheText(2, 2, 2, 2, 2);
                writeOnArdunio(3);
                Callable = false;
            }
            else if (manoj.GetComponent<MeshRenderer>().isVisible)
            {
                Prescription.SetActive(false);
                SetTheText(3, 3, 3, 3, 3);
                writeOnArdunio(4);
                Callable = false;
            }
        }
   /*    if (reading)
        {
            if (ReadFromPort() == false)
            {
                Debug.Log("false");
                reading = false;
              //  SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
            }
            if (ReadFromPort() == true)
            {
                Debug.Log("true");
                reading = false;
               // SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);

            }

        }*/
        


    }


    public IEnumerator writeOnPort(int a)
    {
        int c = 1;
        while (c>0)
        {
            c--;
            yield return new WaitForSeconds(.5f);
            timeleft = timeleft - Time.deltaTime;
            if (sp.IsOpen)
            {

                Debug.Log("Write on port" + " " + a.ToString());
                sp.Write(a.ToString());
                
            }
            yield return null;
            reading = true;
           // break
            /*

            try {
                timeleft = timeleft - Time.deltaTime;
                sp.Open();
                Debug.Log("Write on port" + " " + a.ToString());
                sp.Write(a.ToString());
                
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
            yield return null;
            */
        }
        
    }

    
    public bool ReadFromPort()
    {    //string Received;
         //   float timeleft = 1;
        int i = 10;
        while (true)
        {
            
            try
            {
                Received = sp.ReadLine();
            }
            catch (System.Exception)
            {
                print("Exception occured");
            }
            if(Received == "T")
            {
                Debug.Log("T received");
                return true;
                //break;
            }
            if (Received == "F")
            {
                Debug.Log("F received");
                return false;
                //break;
            }
            i--;
            if(i==1)
            { return false; }

        }
    }

    public void writeOnArdunio(int b)
    {
       StartCoroutine(writeOnPort(b));
    }





    public void SetTheText(int name, int userid, int aadharINT, int DiseaseINT, int medecineINT)
    {
      Fingerprint.SetActive(true);
      Details_Panel.SetActive(true);
      NAME_TEXT.text         = NAMES[name] ;
      USERID_TEXT.text       = userID[userid];
      AADHAR_NO_TEXT.text    = aadhar[aadharINT];
      MEDICINES_TEXT.text    = Medicine[medecineINT];
      Disease_TEXT.text      = Disease[DiseaseINT];
      
    }

    public void VerifyYourFingerprint(int number)
    {
        sp.Write(number.ToString());
        while (true)
        {
            
        }
    }

    public void restart()
    {

    }

}
