using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SceneScoreCounter : MonoBehaviour
{
    public int ScoreCount;
    public GameOneScore One;
    public GameTwoScore Two;
    public GameThreeScore Three;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        ScoreCount = One.ScoreCount + Two.ScoreCount + Three.ScoreCount;
    }
}