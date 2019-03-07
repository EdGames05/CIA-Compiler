/***************************************************************
 * Name:      CIAMain.h
 * Purpose:   Defines Application Frame
 * Author:    Allam (edcompany5@gmailcom)
 * Created:   2019-03-01
 * Copyright: Allam ()
 * License:
 **************************************************************/

#ifndef CIAMAIN_H
#define CIAMAIN_H
#include "Proyecto_cia.h"

//(*Headers(CIAFrame)
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/toolbar.h>
#include <wx/treebook.h>
//*)

class CIAFrame: public wxFrame
{
    public:

        CIAFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~CIAFrame();

    private:

        Proyecto_cia *proyecto;

        //(*Handlers(CIAFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Onitem_salirSelected(wxCommandEvent& event);
        void Onitem_nuevoSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(CIAFrame)
        static const long ID_NOTEBOOK1;
        static const long ID_treeMain;
        static const long ID_btnAbrirProyecto;
        static const long ID_btnNuevoProyecto;
        static const long ID_btnNuevoArchivo;
        static const long ID_btnCerrarProyecto;
        static const long ID_guardarProyecto;
        static const long ID_btnSalir;
        static const long ID_iniciarPrograma;
        static const long ID_detenerPrograma;
        static const long ID_btnCorrer;
        static const long ID_btnDetener;
        static const long ID_toolBar_main;
        //*)

        //(*Declarations(CIAFrame)
        wxFileDialog* FileDialog1;
        wxMenu* Menu1;
        wxMenu* Menu2;
        wxMenuItem* item_abrir;
        wxMenuItem* item_cerrar;
        wxMenuItem* item_detenerPrograma;
        wxMenuItem* item_guardarProyecto;
        wxMenuItem* item_iniciarPrograma;
        wxMenuItem* item_nuevo;
        wxMenuItem* item_nuevoArchivo;
        wxMenuItem* item_salir;
        wxNotebook* panels_main;
        wxToolBar* toolBar_main;
        wxToolBarToolBase* ToolBarItem1;
        wxToolBarToolBase* ToolBarItem2;
        wxTreebook* tree_main;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CIAMAIN_H
