Module updater
    Public Sub updaterfunc()
        Dim dwstring As New System.Net.WebClient
        Dim address As String
        address = "http://techaviationflight.com/lstversion/update.txt"
        Try
            Dim updateversion As String = dwstring.DownloadString(address)
            If Not updateversion.Contains("1.0.0.0") Then
                My.Computer.FileSystem.WriteAllText(Application.StartupPath & "\Updater.bin", "", False)
                Process.Start(Application.StartupPath & "\Updater.exe")
                End
            End If
        Catch

            MsgBox("Impossibile controllare la disponibilita' degli aggiornamenti: ", MsgBoxStyle.Critical, "Error")
        End Try
    End Sub
End Module
