using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;

public class MenuHandling : MonoBehaviour
{
    public XRController leftMenuRay;
    public XRController rightMenuRay;
    public InputHelpers.Button menuActivationButton;
    public GameObject MenuReticle;
    public GameObject MenuLeftCanvas;
    public GameObject MenuRightCanvas;

    // Start is called before the first frame update
    void Start()
    {
        leftMenuRay.gameObject.SetActive(false);
        rightMenuRay.gameObject.SetActive(false);
        MenuReticle.SetActive(false);
        MenuLeftCanvas.SetActive(false);
        MenuRightCanvas.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        if (CheckIfActivated(rightMenuRay))
        {
            leftMenuRay.gameObject.SetActive(false);
            rightMenuRay.gameObject.SetActive(true);
            MenuReticle.SetActive(true);
            MenuLeftCanvas.SetActive(false);
            MenuRightCanvas.SetActive(true);
        }
        if (CheckIfActivated(leftMenuRay))
        {
            leftMenuRay.gameObject.SetActive(true);
            rightMenuRay.gameObject.SetActive(false);
            MenuReticle.SetActive(true);
            MenuLeftCanvas.SetActive(true);
            MenuRightCanvas.SetActive(false);
        }
        if (!CheckIfActivated(leftMenuRay) && !CheckIfActivated(rightMenuRay))
        {
            leftMenuRay.gameObject.SetActive(false);
            rightMenuRay.gameObject.SetActive(false);
            MenuReticle.SetActive(false);
            MenuReticle.SetActive(false);
            MenuLeftCanvas.SetActive(false);
            MenuRightCanvas.SetActive(false);
        }
        if (CheckIfActivated(leftMenuRay) && CheckIfActivated(rightMenuRay))
        {
            leftMenuRay.gameObject.SetActive(false);
            rightMenuRay.gameObject.SetActive(false);
            MenuReticle.SetActive(false);
            MenuReticle.SetActive(false);
            MenuLeftCanvas.SetActive(false);
            MenuRightCanvas.SetActive(false);
        }
    }

    public bool CheckIfActivated(XRController controller)
    {
        InputHelpers.IsPressed(controller.inputDevice, menuActivationButton, out bool isActivated);
        return isActivated;
    }
}
