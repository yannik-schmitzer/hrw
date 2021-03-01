using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameThreeCollision : MonoBehaviour
{
    public int ScoreCount;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Target3")
        {
            ScoreCount = ScoreCount + 1;
        }
    }
    void OnCollisionLeave(Collision col)
    {
        if (col.gameObject.tag == "Target3")
        {
            ScoreCount = ScoreCount - 1;
        }
    }
}