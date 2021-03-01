using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class GameTwoScore : MonoBehaviour
{
    public TextMeshPro Score;
    public int ScoreCount;
    public GameTwoCollision One;
    public GameTwoCollision Two;
    public GameTwoCollision Three;
    public GameTwoCollision Four;
    public GameTwoCollision Five;
    public GameTwoCollision Six;
    public GameTwoCollision Seven;
    public GameTwoCollision Eight;
    public GameTwoCollision Nine;


    // Start is called before the first frame update
    void Start()
    {
        Score.SetText("Pfeilewerfen - Punkte: 0");
    }

    // Update is called once per frame
    void Update()
    {
        ScoreCount = One.ScoreCount + Two.ScoreCount + Three.ScoreCount + Four.ScoreCount + Five.ScoreCount + Six.ScoreCount + Seven.ScoreCount + Eight.ScoreCount + Nine.ScoreCount;
        Score.SetText("Pfeilewerfen - Punkte: {0}", ScoreCount);
    }
}
