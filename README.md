# console_login_and_signup
<p> This is console based application. This application can register new users and allow them to login into their accounts. All the datas are handled in MySQL database. Datas are directly stored in database as well as directly retrieved from database.</p>
<h1> How to run?</h1>  
  Pre-requisites for running the project
  <ul>
<li> Install DEV C++ of 64 bit version from (https://sourceforge.net/projects/orwelldevcpp/)</li>
<li> Install MySQL server of version 8.0 from (https://dev.mysql.com/downloads/installer/)</li>
<li> Install xampp taking (https://www.youtube.com/watch?v=-f8N4FEQWyY&ab_channel=edureka%21) video as reference</li>
  </ul>
  Linking the project to MySQL
  <ul>
<li> In the project menu, select project option</li>
<li> Select Directories</li>
<li> In Library Directory, add the path to the "lib" folder of previously installed MySQL server</li>
<li> In Include Directory, add the path to the "include" folder and "mysql" sub-folder of "include" folder of installed MySQL server</li>
<li> In parameters section, add "-lmysql" and click ok</li>
<li> OR, refer to this (https://www.youtube.com/watch?v=B8fdzMTnOLc&ab_channel=UlisesEspinoza) for reference to link project with MySQL</li>
<li> Add "libmysql.dll", "libcrypto-1_1x64.dll", "libssl-1_1x64.dll" in the folder where your project is located</li> 
  </ul>  
  At last compile and run the project</br></br>
<h1> Features</h1>
<p> Extensive use of database for the collection of data as well as to check from the collected datas if the entered data are present in the database or not</p>
