/***************************************************************
 * Name:      CIAMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Allam (edcompany5@gmailcom)
 * Created:   2019-03-01
 * Copyright: Allam ()
 * License:
 **************************************************************/

#include "CIAMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(CIAFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(CIAFrame)
const long CIAFrame::ID_NOTEBOOK1 = wxNewId();
const long CIAFrame::ID_treeMain = wxNewId();
const long CIAFrame::ID_btnAbrirProyecto = wxNewId();
const long CIAFrame::ID_btnNuevoProyecto = wxNewId();
const long CIAFrame::ID_btnNuevoArchivo = wxNewId();
const long CIAFrame::ID_btnCerrarProyecto = wxNewId();
const long CIAFrame::ID_guardarProyecto = wxNewId();
const long CIAFrame::ID_btnSalir = wxNewId();
const long CIAFrame::ID_iniciarPrograma = wxNewId();
const long CIAFrame::ID_detenerPrograma = wxNewId();
const long CIAFrame::ID_btnCorrer = wxNewId();
const long CIAFrame::ID_btnDetener = wxNewId();
const long CIAFrame::ID_toolBar_main = wxNewId();
//*)

BEGIN_EVENT_TABLE(CIAFrame,wxFrame)
    //(*EventTable(CIAFrame)
    //*)
END_EVENT_TABLE()

CIAFrame::CIAFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(CIAFrame)
    wxMenuBar* menuMain;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1034,472));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\cia_logo.png"))));
    	SetIcon(FrameIcon);
    }
    tree_main = new wxTreebook(this, ID_treeMain, wxPoint(96,248), wxDefaultSize, wxBK_DEFAULT, _T("ID_treeMain"));
    panels_main = new wxNotebook(tree_main, ID_NOTEBOOK1, wxPoint(329,204), wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    tree_main->AddPage(panels_main, _("Raíz"), false);
    menuMain = new wxMenuBar();
    Menu1 = new wxMenu();
    item_abrir = new wxMenuItem(Menu1, ID_btnAbrirProyecto, _("Abrir proyecto"), wxEmptyString, wxITEM_NORMAL);
    item_abrir->SetBitmap(wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\folder_page.png"))));
    Menu1->Append(item_abrir);
    item_nuevo = new wxMenuItem(Menu1, ID_btnNuevoProyecto, _("Nuevo proyecto"), wxEmptyString, wxITEM_NORMAL);
    item_nuevo->SetBitmap(wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\application_add.png"))));
    Menu1->Append(item_nuevo);
    item_nuevoArchivo = new wxMenuItem(Menu1, ID_btnNuevoArchivo, _("Nuevo Archivo"), wxEmptyString, wxITEM_NORMAL);
    item_nuevoArchivo->SetBitmap(wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\page_add.png"))));
    Menu1->Append(item_nuevoArchivo);
    item_cerrar = new wxMenuItem(Menu1, ID_btnCerrarProyecto, _("Cerrar proyecto"), wxEmptyString, wxITEM_NORMAL);
    item_cerrar->SetBitmap(wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\page.png"))));
    Menu1->Append(item_cerrar);
    item_guardarProyecto = new wxMenuItem(Menu1, ID_guardarProyecto, _("Guardar"), wxEmptyString, wxITEM_NORMAL);
    item_guardarProyecto->SetBitmap(wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\script_save.png"))));
    Menu1->Append(item_guardarProyecto);
    Menu1->AppendSeparator();
    item_salir = new wxMenuItem(Menu1, ID_btnSalir, _("Salir"), wxEmptyString, wxITEM_NORMAL);
    item_salir->SetBitmap(wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\door_out.png"))));
    Menu1->Append(item_salir);
    menuMain->Append(Menu1, _("&Archivo"));
    Menu2 = new wxMenu();
    item_iniciarPrograma = new wxMenuItem(Menu2, ID_iniciarPrograma, _("Iniciar programa"), wxEmptyString, wxITEM_NORMAL);
    item_iniciarPrograma->SetBitmap(wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\control_play_blue.png"))));
    Menu2->Append(item_iniciarPrograma);
    item_detenerPrograma = new wxMenuItem(Menu2, ID_detenerPrograma, _("Detener programa"), wxEmptyString, wxITEM_NORMAL);
    item_detenerPrograma->SetBitmap(wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\control_stop_blue.png"))));
    Menu2->Append(item_detenerPrograma);
    menuMain->Append(Menu2, _("Depurar"));
    SetMenuBar(menuMain);
    toolBar_main = new wxToolBar(this, ID_toolBar_main, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_toolBar_main"));
    toolBar_main->AddSeparator();
    ToolBarItem1 = toolBar_main->AddTool(ID_btnCorrer, wxEmptyString, wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\control_play_blue.png"))), wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\control_play.png"))), wxITEM_NORMAL, _("Iniciar programa"), wxEmptyString);
    ToolBarItem2 = toolBar_main->AddTool(ID_btnDetener, wxEmptyString, wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\control_stop_blue.png"))), wxBitmap(wxImage(_T("C:\\Librerias desarrollo\\CIA\\img\\control_stop.png"))), wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    toolBar_main->Realize();
    SetToolBar(toolBar_main);
    FileDialog1 = new wxFileDialog(this, _("Archivo CIA"), wxEmptyString, _("*.ala"), wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    Connect(ID_btnNuevoProyecto,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CIAFrame::Onitem_nuevoSelected);
    Connect(ID_btnSalir,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CIAFrame::Onitem_salirSelected);
    //*)
    this->ToolBarItem2->Enable(false);
    FileDialog1->SetWildcard("Archivo ala (*.ala) | *.ala");
    this->proyecto = new Proyecto_cia();
}

CIAFrame::~CIAFrame()
{
    //(*Destroy(CIAFrame)
    //*)
}

void CIAFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CIAFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void CIAFrame::Onitem_salirSelected(wxCommandEvent& event)
{
    this->Close(true);
}

void CIAFrame::Onitem_nuevoSelected(wxCommandEvent& event)
{
    FileDialog1->SetWindowStyleFlag(wxFD_SAVE);
    int filedia = FileDialog1->ShowModal();
    if(filedia == wxID_OK){
        if(proyecto->nuevo_proyecto(FileDialog1->GetFilename().mb_str(),"principal.cia",FileDialog1->GetDirectory())){
            wxMessageBox("Archivo creado","Archivo");
        }
        else{
            wxMessageBox("Error inesperado...","Archivo");
        }
    }
}
