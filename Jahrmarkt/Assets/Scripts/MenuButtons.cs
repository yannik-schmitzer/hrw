using System.Collections;
using System.Collections.Generic;
using System.Runtime.Hosting;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;

public class MenuButtons : MonoBehaviour
{
    private const int SceneTraining = 0;
    private const int SceneGame = 1;
    // Start is called before the first frame update
    void Start()
    {
        
    }
    public void Reset()
    {
        SceneManager.LoadScene(SceneTraining);
    }
    public void Close()
    {
        Application.Quit();
    }
    public void Play()
    {
        SceneManager.LoadScene(SceneGame);
    }
    public void Train()
    {
        SceneManager.LoadScene(SceneTraining);
    }
    public void Restart()
    {
        SceneManager.LoadScene(SceneGame);
    }
}
