using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SceneThrowCounter : MonoBehaviour
{
    public int ThrowCount;
    public GameThrowCounter One;
    public GameThrowCounter Two;
    public GameThrowCounter Three;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        ThrowCount = One.ThrowCount + Two.ThrowCount + Three.ThrowCount;
    }
}
