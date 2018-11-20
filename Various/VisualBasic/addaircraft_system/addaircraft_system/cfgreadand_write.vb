Imports addaircraft_system
Imports System.IO
Imports System.Runtime.InteropServices
Imports System.Text
Imports System.Security.Permissions
Module cfgreadand_write
    Dim Dir As String
    Dim ReadNum As Integer
    Dim Line As String
    Dim ATC_Airline As String
    Dim UI_Var As String
    Dim Title As String
    Dim fltsim As String
    Dim a_Airline() As String
    Dim a_Aircraft() As String
    Dim a_Relationship() As String
    Dim n As Integer
    Dim bFstTime1 As Boolean = True
    Dim bFstTime2 As Boolean
    Dim bDuplicate1 As Boolean
    Dim bDuplicate2 As Boolean
    Dim Speed As String
    Dim Range As String
    Dim Ceiling As String
    Dim Span As String
    Public Sub cercasub()
        Dim path As String = "H:\prove\aircraft.ini"
        Dim logpath As String = "H:\prove\test.txt"
        Dim Riga As String
        Dim count As Integer
        Dim logcounter As Integer
        Dim pathperm As New FileIOPermission(FileIOPermissionAccess.AllAccess, "H:\prove\aircraft.ini")
        Dim logpathperm As New FileIOPermission(FileIOPermissionAccess.AllAccess, "H:\prove\test.txt")
        bFstTime1 = True
        bFstTime2 = True
        ReDim a_Airline(0)
        ReDim a_Aircraft(0)
        ReDim a_Relationship(0)
        Debug.Write(path)
        Debug.Write(logpath)
        pathperm.AddPathList(FileIOPermissionAccess.AllAccess, "H:\prove\aircraft.ini")
        logpathperm.AddPathList(FileIOPermissionAccess.AllAccess, "H:\prove\test.txt")
        Debug.Write(logpathperm)

        Do While path <> ""
            If File.Exists(path) Then
                count = FreeFile()
                logcounter = FreeFile()
                FileOpen(count, path, OpenMode.Input, OpenAccess.Read)
                Input(count, Riga)
                If path = path Then
                    FileOpen(logcounter, logpath, OpenMode.Output, OpenAccess.Write, OpenShare.LockReadWrite)
                    Print(logcounter, Riga)
                    fltsim = ""
                    ATC_Airline = ""
                    Title = ""
                    UI_Var = ""
                    Do While Not EOF(count)
                        Input(count, Riga)
                        Riga = Trim(Riga)
                        If path = path Then
                            If Len(Riga) Then
                                InStr(1, Riga, "[fltsim.")
                                If fltsim <> Riga Then
                                    Len(ATC_Airline)
                                    If ATC_Airline = "SHOW-ME" Then Stop
                                    AddAirline()
                                    ATC_Airline = ""
                                End If
                                If Len(Title) Then
                                    AddAircraft()
                                    Title = ""
                                    UI_Var = ""
                                    ATC_Airline = ""
                                End If
                            End If
                            fltsim = Riga
                        End If
                        ' Gets the values
                        If InStr(1, LCase(Riga), "atc_airline=") Then If Len(Right(Riga, Len(Riga) - 12)) Then ATC_Airline = Trim(Right(Riga, Len(Riga) - 12))
                        If InStr(1, LCase(Riga), "ui_variation=") Then If Len(Right(Riga, Len(Riga) - 13)) Then UI_Var = Trim(Right(Riga, Len(Riga) - 13))
                        If InStr(1, LCase(Riga), "title=") Then Title = Trim(Right(Riga, Len(Riga) - 6))
                    Loop
                    If Len(ATC_Airline) Then AddAirline()
                    If Len(Title) Then AddAircraft()
                    ATC_Airline = ""
                    Title = ""
                    UI_Var = ""
                    FileClose(count)
                    path = path

                End If
            End If
        Loop
        'FileClose(logcounter)
        Debug.Write(a_Airline)
        Debug.Write(a_Aircraft)
        Debug.Write(a_Relationship)

    End Sub
    Public Sub AddAirline()
        ' Look for duplicates
        ATC_Airline = UCase(ATC_Airline)
        For n = 0 To UBound(a_Airline)
            If a_Airline(n) = ATC_Airline Then bDuplicate1 = True
        Next n

        If Not bDuplicate1 Then
            If Not bFstTime1 Then
                ReDim Preserve a_Airline(UBound(a_Airline) + 1)
            Else
                bFstTime1 = False
            End If
            a_Airline(UBound(a_Airline)) = ATC_Airline
        Else
            bDuplicate1 = False
        End If
    End Sub
    Public Sub AddAircraft()
        ' Look for duplicates
        For n = 0 To UBound(a_Aircraft)
            If a_Aircraft(n) = Title Then bDuplicate2 = True
        Next n

        ' Add to array
        If Not bDuplicate2 Then
            If Not bFstTime2 Then
                ReDim Preserve a_Aircraft(UBound(a_Aircraft) + 1)
                ReDim Preserve a_Relationship(UBound(a_Relationship) + 1)
            Else
                bFstTime2 = False
            End If
            Mid(Title, 1, 1) = UCase(Mid(Title, 1, 1))
            a_Aircraft(UBound(a_Aircraft)) = Title & " [" & UI_Var & "]" & "/~/" & Dir

            ' Relationship
            If UCase(ATC_Airline) = "" Then ATC_Airline = "GENERAL AVIATION"
            a_Relationship(UBound(a_Relationship)) = UCase(ATC_Airline) & "/~/" & Title & " [" & UI_Var & "]" & "/~/" & Dir
        Else
            bDuplicate2 = False
        End If
    End Sub
End Module
