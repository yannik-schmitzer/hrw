using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class TimeSinceLevelLoad : MonoBehaviour
{
    public TextMeshPro Timer;
    public SceneThrowCounter Thrown;
    public SceneScoreCounter ScoreCount;
    private float TimeScore;

    // Start is called before the first frame update
    void Start()
    {
        Timer.SetText("Benötigte Zeit: 0 | Punktzahl: 0");
    }

    // Update is called once per frame
    void Update()
    {
        if(Thrown.ThrowCount < 27)
        {
            Timer.SetText("Benötigte Zeit: {0} | Punktzahl: {1}", Time.timeSinceLevelLoad, ScoreCount.ScoreCount);
        }
        else
        {
            Timer.SetText("Benötigte Zeit: {0} | Punktzahl: {1}", Time.timeSinceLevelLoad, ScoreCount.ScoreCount);
            this.enabled = false;
        }
    }
}
