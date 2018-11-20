Imports MySql.Data.MySqlClient

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' connection function.This function connect to a MySql database:
' this code refer to a localhost server.For other db you may 
' change the connection options, for more info refer to MySql Connector Assembly Doc
' <https://dev.mysql.com/doc/connector-net/en/connector-net-connection-options.html>
' This code refer to the General License Agreedment.
' Copyright By Giorgio Bella 2018
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Module connection
    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    ' NOTE: You can not perform tow actions in the same time
    ' you must dispose the conn object before openig a new one
    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    Public Function Conne()
        Dim conn As New MySql.Data.MySqlClient.MySqlConnection
        Dim myConnectionString As String
        'Initializing connnection options format to string'
        myConnectionString = "Server=localhost;" _
            & "Uid=root;" _
            & "pwd=Cn2e8LXWnAp4vGCr6ryvsW6n;" _
            & "Database=sys;" _
            & "Connect Timeout=30;" _
            & "Protocol=unix;" _
            & "SslMode=required;" _
            & "sqlservermode=true;" _
            & "port=3306"

        Try
            'put the connection openig in a try to avoid exeptions
            conn = New MySqlConnection(myConnectionString)
            conn.Open()
            'MsgBox("open") Debug process 
            loginfunc(conn)
            'write(conn, myConnectionString)
            conn.Close()
        Catch ex As MySqlException
            MessageBox.Show(ex.Message.ToString)
        End Try
        Return conn 'returnig data for all other module that use this function 
        Return myConnectionString 'returnig data for all other module that use this function 
        conn.Dispose()
    End Function
End Module
