Imports addaircraft_system
Imports System.IO
Imports System.Runtime.InteropServices
Imports System.Text
Imports System.Security.Permissions

Module Module2
    Public Sub read()
        Dim caunter As Integer
        Dim aircraft As String

        aircraft = System.IO.File.ReadAllText("H:\prove\aircraft.ini")
        caunter = 0
        Try
            Dim riga As String
            Dim sr As New StreamReader("H:\prove\aircraft.ini")
            Do
                riga = sr.ReadLine()
                Debug.WriteLine(riga)
                ' If InStr(1, aircraft, "[fltsim.") = True Then
                'caunter = caunter + 1
                'End If
            Loop Until riga Is Nothing
            sr.Close()
        Catch ex As Exception
            ' Let the user know what went wrong.
            Console.WriteLine("The file could not be read:")
            Console.WriteLine(ex.Message)
        End Try
        MsgBox(caunter)
    End Sub
    <DllImport("kernel32.dll", SetLastError:=True)>
    Private Function GetPrivateProfileString(ByVal lpAppName As String, ByVal lpKeyName As String, ByVal lpDefault As String, ByVal lpReturnedString As StringBuilder, ByVal nSize As Integer, ByVal lpFileName As String) As Integer
    End Function
    <DllImport("kernel32.dll", SetLastError:=True)>
    Private Function WritePrivateProfileString(ByVal lpAppName As String, ByVal lpKeyName As String, ByVal lpString As String, ByVal lpFileName As String) As Boolean
    End Function
    <DllImport("kernel32.dll", SetLastError:=True)>
    Private Function GetPrivateProfileSectionNames(ByVal strTypeList As String, ByVal dblListLen As Long, ByVal strIniFileName As String) As Long
    End Function
    <DllImport("kernel32.dll", SetLastError:=True)>
    Private Function GetPrivateProfileSection(ByVal strSelSectName As String, ByVal strSectData As String, ByVal dblListLen As Long, ByVal strIniFileName As String) As Long
    End Function
    Public Function IniWrite(ByVal Filename As String, ByVal Section As String, ByVal Key As String, ByVal Value As String, Optional ByVal bRaiseError As Boolean = False) As Boolean

        Dim LenResult As Integer

        Dim ErrString As String

        LenResult = WritePrivateProfileString(Section, Key, Value, Filename)

        If LenResult = 0 And bRaiseError Then

            If Not (System.IO.File.Exists(Filename)) Then

                ErrString = “Impossibile aprire il file INI” & Filename

            Else

                ErrString = “Accesso al file non consentito”

            End If

            Throw New Exception(ErrString)

        End If

        Return IIf(LenResult = 0, False, True)

        End

    End Function
End Module
