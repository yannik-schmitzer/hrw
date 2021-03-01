using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class GameThreeScore : MonoBehaviour
{
    public TextMeshPro Score;
    public int ScoreCount;
    public GameThreeCollision One;
    public GameThreeCollision Two;
    public GameThreeCollision Three;
    public GameThreeCollision Four;
    public GameThreeCollision Five;
    public GameThreeCollision Six;
    public GameThreeCollision Seven;
    public GameThreeCollision Eight;
    public GameThreeCollision Nine;

    // Start is called before the first frame update
    void Start()
    {
        Score.SetText("Bällewerfen - Punkte: 0");
    }

    // Update is called once per frame
    void Update()
    {
        ScoreCount = One.ScoreCount + Two.ScoreCount + Three.ScoreCount + Four.ScoreCount + Five.ScoreCount + Six.ScoreCount + Seven.ScoreCount + Eight.ScoreCount + Nine.ScoreCount;
        Score.SetText("Bällewerfen - Punkte: {0}", ScoreCount);
    }
}



