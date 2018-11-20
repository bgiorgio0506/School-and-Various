Imports addaircraft_system
Imports System.IO
Imports System.Runtime.InteropServices
Imports System.Text
Imports System
Public Class Form1
    Dim caunter As Integer
    Private Function Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click

        caunter = 0
        Try
            Dim riga As String
            Dim sr As New StreamReader("H:\prove\test.ini")
            Do
                riga = sr.ReadLine()
                Debug.WriteLine(riga)
                If InStr(1, riga, "[fltsim.") Then
                    caunter = caunter + 1
                End If
            Loop Until riga Is Nothing
            MsgBox(caunter)
            sr.Close()
        Catch ex As Exception
            'Let the user know what went wrong.
            Console.WriteLine("The file could not be read:")
            Console.WriteLine(ex.Message)
        End Try
        Return caunter
    End Function
    Public Sub addcfg(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        Try
            Dim righecounter As Integer = 0
            Dim rowgeneral As String
            Dim sr As New StreamReader("H:\prove\aircraft.ini")
            Do
                rowgeneral = sr.ReadLine
                righecounter = righecounter + 1
                If InStr(1, rowgeneral, "[General]") Then Exit Do
            Loop Until rowgeneral Is Nothing
            MsgBox(righecounter)
            sr.Close()
        Catch ex As Exception
            'Let the user know what went wrong.
            Console.WriteLine("The file could not be read:")
            Console.WriteLine(ex.Message)
        End Try
    End Sub
    Public Sub writeline(sender As System.Object, e As System.EventArgs) Handles Button3.Click
        Dim x As String
        x = Button1_Click(sender, e)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “title”, “PMDG 738 AVIONORD LIVERYMANAGER TEST”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “sim”, “B737-800WL”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “model”, “”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “panel”, “”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “sound”, “”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “texture”, “vnd”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “kb_checklists”, “Boeing737 - 800_check”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “kb_reference”, “Boeing737 - 800_Ref”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “ATC_Airline”, “AVIONORD”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “atc_id”, “I-STVE”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “atc_flight_number”, “209”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “atc_model”, “737-800”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “atc_parking_types”, “GATE,RAMP”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “atc_type”, “BOEING”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “ui_createdby”, “PMDG”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “ui_manufacturer”, “Boeing”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “ui_type”, “737-800NGX”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “ui_typerole”, “737-800”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “ui_variation”, “Avionord Winglets”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “airline_name”, “Avionord”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “description”, “ Boeing 737-800 powered by CFM engines v 1.0\nPMDG Simulations\nwww.precisionmanuals.com \n\nProduced under license from Boeing Management Company.\n\nBoeing 737, 737-800 & Boeing are among the trademarks owned by Boeing.”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “visual_damage”, “0”)
        IniWrite(“H:\prove\test.ini”, “fltsim." + x, “PMDG_Version”, “1 // **DO Not EDIT THIS LINE - AVIONORD OPERATIONS CENTER USE ONLY**”)
    End Sub
    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click

    End Sub
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        updaterfunc()
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Dim test2 As IO.StreamWriter = IO.File.CreateText(“H:\prove\test2.txt”)
        Dim qr = From data In IO.File.ReadAllText(“H:\prove\test.txt”)
        Dim testo As String = qr
        Dim split As String() = testo.Split("[]")

    End Sub
End Class

