Imports MySql.Data.MySqlClient
Imports databaseconntest_ù
Imports System.IO
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' Read and write module.This module connect to a MySql database and compere the input
' to the credetial stored to the Msql Database.
' For more info refer to MySql Connector Assembly Doc
' <https://dev.mysql.com/doc/connector-net/en/connector-net-connection-options.html>
' This code refer to the General License Agreedment.
' Copyright By Giorgio Bella 2018
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Module read_write
    Dim sql As String
    Dim sqlCommand As New MySqlCommand
    Dim datareader As MySqlDataReader
    Dim nome As String
    Dim password As String
    Dim login As Boolean

    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    ' NOTE: You can not perform tow actions in the same time
    ' you must dispose the conn object before openig a new one
    '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

    Public Sub loginfunc(ByRef conn)
        ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        ' NOTE: For now this sub don't support encrypted passwords 
        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        Try
            nome = LoginForm1.UsernameTextBox.Text 'take data from the text box and stored to a string variable
            password = LoginForm1.PasswordTextBox.Text 'take data from the text box and stored to a string variable
            sql = "SELECT * FROM iscritti WHERE nome='" & nome & "'and password='" & password & "'"     ' Query to perform basicly this query look for a name and password in the database
            ' For more security I suggest to encrypt the password given by the user and send it vai ssl connection to the database
            sqlCommand = New MySqlCommand(sql, conn)
            datareader = sqlCommand.ExecuteReader() 'start the reader 
            While datareader.Read 'if the query is satisfied login var become true
                login = True
            End While
            datareader.Close()
            'result output 
            If (login = True) Then
                MsgBox("Login Successfull")
            Else
                MsgBox("Username and Password are wrong")
            End If
        Catch ex As Exception
            MsgBox("Problem While connecting to our server: " & ex.Message.ToString) ' if there is any problem before or during the query this cath it as exeption 
        End Try
    End Sub
    Public Sub write(ByRef conn, ByRef connectionString)
        ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        ' NOTE: You have two way to set up the query the first one that is commented and the second one that is the actual code
        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        'Dim var As String
        'var=...
        'sql = "INSERT INTO iscritti(ID,nome,cognome,mail,data_nascita,vid, password) VALUES(NULL,'"var"','****','******@domain.com','0000-00-00','56789','Lalalala01')"

        sql = "INSERT INTO iscritti(ID,nome,cognome,mail,data_nascita,vid, password) VALUES(NULL,'******','****','*****@domain.com','0000-00-00','56789','Lalalala01')"
        Try
            sqlCommand = New MySqlCommand(sql, conn)
            datareader = sqlCommand.ExecuteReader()
            datareader.Close()
            MsgBox("Data Inserted")
        Catch ex As Exception
            MsgBox("Problem loading data: " & ex.Message.ToString)
        End Try
    End Sub
End Module
