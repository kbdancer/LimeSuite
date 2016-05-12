#ifndef PNL_QSPARK_H
#define PNL_QSPARK_H

#include <map>
#include <wx/frame.h>
#include <wx/panel.h>
#include "lime/LimeSuite.h"
class wxStaticText;
class wxFlexGridSizer;
class wxButton;
class wxSpinCtrl;
class wxComboBox;
class wxCheckBox;
class wxTextCtrl;
class wxChoice;



class pnlQSpark : public wxFrame
{
public:
    pnlQSpark(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString &title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int style = 0, wxString name = "");
    void Initialize(lms_device_t *pControl);
    virtual ~pnlQSpark();
    virtual void UpdatePanel();

    wxButton* btnUpdateAll;
    wxComboBox* cmbVCXOcontrolVoltage;

    wxPanel* mPanelStreamPLL;
    wxTextCtrl* txtPllFreqRxMHz;
    wxStaticText* lblRealFreqTx;
    wxStaticText* lblRealFreqRx;
    wxTextCtrl* txtPllFreqTxMHz;
    wxTextCtrl* txtPhaseOffsetDeg;
    wxButton* btnConfigurePLL;

    wxCheckBox* chkEN_TXTSP;
    wxCheckBox* chkEN_RXTSP;
    wxCheckBox* chkRX_DCCORR_BYP;
    wxCheckBox* chkRX_PHCORR_BYP;
    wxCheckBox* chkRX_GCORR_BYP;
    wxCheckBox* chkTX_DCCORR_BYP;
    wxCheckBox* chkTX_PHCORR_BYP;
    wxCheckBox* chkTX_GCORR_BYP;
    wxSpinCtrl* spinTX_DCCORRI;
    wxSpinCtrl* spinTX_DCCORRQ;
    wxSpinCtrl* spinTX_GCORRQ;
    wxSpinCtrl* spinTX_GCORRI;
    wxSpinCtrl* spinTX_PHCORR;
    wxSpinCtrl* spinRX_GCORRQ;
    wxSpinCtrl* spinRX_GCORRI;
    wxSpinCtrl* spinRX_PHCORR;
    wxChoice* cmbInsel;

    wxTextCtrl* txtNcoFreq;

    static const long ID_BUTTON_UPDATEALL;
    static const long ID_VCXOCV;

    void OnbtnUpdateAll(wxCommandEvent& event);
    void OnNcoFrequencyChanged(wxCommandEvent& event);
protected:
    void OnConfigurePLL(wxCommandEvent &event);

    struct Register
    {
        Register();
        Register(unsigned short address, unsigned char msb, unsigned char lsb, unsigned short defaultValue);
        unsigned short address;
        unsigned char msb;
        unsigned char lsb;
        unsigned short defaultValue;
    };
    std::map<wxObject*, Register> controlsPtr2Registers;
    void RegisterParameterChangeHandler(wxCommandEvent& event);

protected:
    lms_device_t *lmsControl;
    DECLARE_EVENT_TABLE()
};

#endif
