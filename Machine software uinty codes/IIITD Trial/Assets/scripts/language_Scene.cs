using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class language_Scene : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
    public void LoadEnglish()
    {
        SceneManager.LoadScene("english");
    }
    public void LoadHindi()
    {
        SceneManager.LoadScene("hindi");
    }
}
