using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class GameOneScore : MonoBehaviour
{
    public TextMeshPro Score;
    public int ScoreCount;
    public GameOneCollision One;
    public GameOneCollision Two;
    public GameOneCollision Three;
    public GameOneCollision Four;
    public GameOneCollision Five;
    public GameOneCollision Six;
    public GameOneCollision Seven;
    public GameOneCollision Eight;
    public GameOneCollision Nine;
    public GameOneCollision Ten;
    public GameOneCollision Eleven;
    public GameOneCollision Twelve;
    public GameOneCollision Thirteen;
    public GameOneCollision Fourteen;
    public GameOneCollision Fifteen;
    public GameOneCollision Sixteen;
    public GameOneCollision Seventeen;
    public GameOneCollision Eighteen;
    // Start is called before the first frame update
    void Start()
    {
        Score.SetText("Dosenwerfen - Punkte: 0");
    }

    // Update is called once per frame
    void Update()
    {
        ScoreCount = One.ScoreCount + Two.ScoreCount + Three.ScoreCount + Four.ScoreCount + Five.ScoreCount + Six.ScoreCount + Seven.ScoreCount + Eight.ScoreCount + Nine.ScoreCount + Ten.ScoreCount + Eleven.ScoreCount + Twelve.ScoreCount + Thirteen.ScoreCount + Fourteen.ScoreCount + Fifteen.ScoreCount + Sixteen.ScoreCount + Seventeen.ScoreCount + Eighteen.ScoreCount;
        Score.SetText("Dosenwerfen - Punkte: {0}", ScoreCount);
    }
}



