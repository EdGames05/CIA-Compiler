/***************************************************************
 * Name:      CIAApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Allam (edcompany5@gmailcom)
 * Created:   2019-03-01
 * Copyright: Allam ()
 * License:
 **************************************************************/

#include "CIAApp.h"

//(*AppHeaders
#include "CIAMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CIAApp);

bool CIAApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	CIAFrame* Frame = new CIAFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
