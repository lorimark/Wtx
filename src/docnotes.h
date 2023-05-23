/**************************************************************************
###########################################################################
##
## $SHOWOFFDB_BEGIN_LICENSE$
## Copyright (C) 2011 Lorimark Solutions, LLC and/or its subsidiary(-ies).
##  All rights reserved.
##  Contact: Lorimark Solutions, LLC (info@showoff-db.org)
##
## This file is part of the Showoff Database Application Framework.
##
##  Commercial Usage
##  Licensees holding valid ShowoffDB Commercial licenses may use this file in
##   accordance with the ShowoffDB Commercial License Agreement provided with the
##   Software or, alternatively, in accordance with the terms contained in
##   a written agreement between you and Lorimark Solutions, LLC.
##
## GNU Lesser General Public License Usage
##  Alternatively, this file may be used under the terms of the GNU Lesser
##   General Public License version 2.1 as published by the Free Software
##   Foundation and appearing in the file LICENSE.LGPL included in the
##   packaging of this file.  Please review the following information to
##   ensure the GNU Lesser General Public License version 2.1 requirements
##   will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
##
## In addition, as a special exception, Lorimark Solutions, LLC gives
##  you certain additional rights.  These rights are described in the
##  Lorimark Solutions, LLC ShowoffDB LGPL Exception version 1.0, included in
##  the file LGPL_EXCEPTION.txt in this package.
##
## GNU General Public License Usage
##  Alternatively, this file may be used under the terms of the GNU
##   General Public License version 3.0 as published by the Free Software
##   Foundation and appearing in the file LICENSE.GPL included in the
##   packaging of this file.  Please review the following information to
##   ensure the GNU General Public License version 3.0 requirements will be
##   met: http://www.gnu.org/copyleft/gpl.html.
##
## If you have questions regarding the use of this file, please contact
##   Lorimark Solutions, LLC at info@showoff-db.org.
## $SHOWOFFDB_END_LICENSE$
##
#############################################################################
****************************************************************************/


/*!
** \mainpage Wt Extension Library Developers Documentation
**
** The Wtx is an extension library built expressly for the Wt web development
**  tool kit.  The Wt web development tool kit can be found here:
**  https://www.webtoolkit.eu/wt
**
** The Wt tool kit is an incredible tool for building rediculously fast websites using
**  c++.  Wt includes an extremely powerful back-end database library for serializing
**  c++ objects directly in to a database.  You can read about that here:
**  https://www.webtoolkit.eu/wt/doc/tutorial/dbo.html
**
** The Wt tool kit also includes a very powerful front-end widget library for building
**  websites the "object-oriented way" as well as the "c++ way".  You can read about
**  the widget library here: https://webtoolkit.eu/widgets
**
** All that is left for the programmer, then, is to build all the middle-ware connecting
**  the "database" objects to the "user interface" objects... and this is where the Wtx
**  library comes in.
**
** The Wtx library strives to simplify all of the glue logic between the c++ classes
**  and the website user interfaces.  It allows the programmer to focus on the operational
**  logic of the programming task, and less on the "grunt work" of binding c++ classes
**  to back-end databases and front-end user interfaces.
**
** This can be best explained by reviewing the documentation for the TableView,
**  where a table-view is constructed easily with a simply table-view-definition and
**  then a simple call to the table view constructor.  You can read more about that
**  here: Wtx::TableViewDef
**
** To get started with a simple server, refer to the page '\ref simple_linux_server'
*/


/*!
** \page postgres_tricks Postgres SQL Tricks
**
** This is a page I stumbled in to that shows a whole bunch
**  of different SQL tricks.
**
**
** https://postgres.cz/wiki/PostgreSQL_SQL_Tricks
**
*/



/*!
** \page wtfaq Wt FAQ
**
** The following is a list of common questions and their answers. We've
**  tried to capture as much as possible about the Wt ecosystem here. If you have
**  a question that is not answered here, send an email to mark@lorimarksolutions.com
**
** \par How do I make a simple static file server?
**
** \ref simple_linux_server
**
** \par How do I make an advanced 'live-widget' server?
**
** \ref active_linux_server
**
** \par How do I add a datbase my server?
**
** \ref active_linux_with_dbo
**
** \par How do I make a user-login for my server?
**
** \ref active_linux_with_user_auth
**
** \par how do i get a table-view with 100's or 1000's of rows of data to display properly?
**
** \ref wlayout_and_wtableview
**
** \par how do I make my site look good on mobile as well as desktop
**
** \ref mobile_friendly
*/


/*!
** \page simple_linux_server Part 1 ~ Creating a Simple (linux) Wt4 "static file" Server from Scratch
**
** This tutorial describes the steps necessary to install Wt-4 on a Linux computer
**  and set up a simple web server, providing a base platform from which to develop
**  sophisticated websites and web services using Wt.  These instructions are
**  applicable to the Wt-3 library version also, but this whole tutorial is written
**  for Wt-4.
**
** The steps are (relatively) fairly simple, as follows:
** -# download and install Wt
** -# create a project folder
** -# create project files
** -# build and run project
**
** Note that it is possible to develop and deploy a Wt server a half-dozen different
**  ways.  The following notes describe how I do it, and, by no means, should be considered
**  good or proper or right.  These procedures work for me.  Your mileage may vary.
**
** If you have any comments or suggestions or additions, please email them to me
**  at mark@lorimarksolutions.com.
**
** ### 1. download and install Wt
**
** Instructions for downloading and installing Wt can be found directly on the Wt
**  website:
**
** \code
** https://www.webtoolkit.eu/wt/download
** \endcode
**
** The procedure I use to build Wt is to fetch the source from their git repository
**  directly.  This insures that I have the latest source code, and can keep the
**  libraries up to date at any point in time:
**
** \code
** mark@lsus1 ~/projects $ git clone https://github.com/emweb/wt.git
** Cloning into 'wt'...
** remote: Counting objects: 36993, done.
** remote: Compressing objects: 100% (272/272), done.
** remote: Total 36993 (delta 269), reused 194 (delta 124), pack-reused 36596
** Receiving objects: 100% (36993/36993), 29.56 MiB | 2.97 MiB/s, done.
** Resolving deltas: 100% (30446/30446), done.
** Checking connectivity... done.
** \endcode
**
** There should now be a directory called 'wt' in the project folder, containing
**  all of the Wt source codes.  Next step is to enter in to the Wt folder and
**  set up the build environment:
**
** \code
** mark@lsus1 ~/projects $ cd wt
** mark@lsus1 ~/projects/wt $ mkdir build
** mark@lsus1 ~/projects/wt $ cd build
** mark@lsus1 ~/projects/wt/build $
** \endcode
**
** Now the source can be compiled.  I use a set of build-flags to cause Wt
**  to get installed in to a location that will uniquely separate it from
**  any other Wt installations, allowing me to develop using the Wt3 library
**  set or the Wt4 library set, independently and in parallel.  There are a
**  handful of compiler options that you should review to decide what features
**  and functions you want in your library binaries.
**
** There are times when I want to hack the Wt library, but not disturb the
**  existing installation.  So what I do is clone the wt directory in to a
**  special directory, do my hacking, change the CMAKE_INSTALL_PREFIX to
**  something different, recompile, install and get to testing.
**
** \code
** mark@lsus1:~/projects/wt/build $ cmake \
** >   -DCMAKE_INSTALL_PREFIX=/opt/Wt4 \
** >   -DWT_WRASTERIMAGE_IMPLEMENTATION=GraphicsMagick \
** >   -DCONNECTOR_FCGI=OFF \
** >   ..
** -- The CXX compiler identification is GNU 5.4.0
** -- Check for working C compiler: /usr/bin/cc
** -- Check for working C compiler: /usr/bin/cc -- works
** -- Detecting C compiler ABI info - done
** -- Detecting C compile features - done
** -- Check for working CXX compiler: /usr/bin/c++ -- works
** -- Detecting CXX compiler ABI info - done
** -- Detecting CXX compile features - done
** --
** -- much talking...
** --
** -- Boost version: 1.58.0
** -- Found the following Boost libraries:
** --   program_options
** --   date_time
** --   atomic
** -- Found png libraries
** -- Found libharu libraries
** -- Looking for sin
** -- Looking for sin - not found
** -- Found unsuitable Qt version "5.7.0" from /opt/Qt5.7.0/5.7/gcc_64/bin/qmake
** ** Wt::Dbo: building Postgres backend.
** ** Wt::Dbo: not building Firebird backend.
**    Indicate the location of your FirebirdSQL and IBPP installation using 
** ** Wt::Dbo: not building Microsoft SQL Server backend.
** ** Disabling ISAPI.
** -- Looking for crypt - not found
** -- Looking for crypt in crypt
** -- Looking for crypt in crypt - found
** -- Build files have been written to: /home/mark/projects/wt/build
** \endcode
**
** Placing the /opt/Wt4 on the install prefix setting causes the Wt target
**  libraries to be installed in to that directory location.  By installing
**  the Wt libraries in to the /opt folder allows the library to be globally
**  available to any user on the system.  You can optionally install to the
**  users /home causing the library to only be available to that user's
**  folder with the following:
**
** \code
** mark@lsus1:~/projects/wt/build $ cmake \
** >   -DCMAKE_INSTALL_PREFIX=~/builds/Wt4 \
** >   -DWT_WRASTERIMAGE_IMPLEMENTATION=GraphicsMagick \
** >   -DCONNECTOR_FCGI=OFF \
** >   ..
*** \endcode
**
** Now the library can be built.
**
** \code
** mark@lsus1:~/projects/wt/build $ make
** Scanning dependencies of target wtdbo
** [  0%] Generating JQuery_js.C
** [  1%] Generating Boot_html.C
** [  1%] Generating Boot_js.C
** [  1%] Building CXX object src/Wt/Dbo/CMakeFiles/wtdbo.dir/Call.C.o
** [  3%] Generating BootstrapTheme_xml.C
** [  3%] Building CXX object src/Wt/Dbo/CMakeFiles/wtdbo.dir/ptr.C.o
** [  3%] Building CXX object src/Wt/Dbo/CMakeFiles/wtdbo.dir/FixedSqlConnectionPool.C.o
** [  4%] Building CXX object src/Wt/Dbo/CMakeFiles/wtdbo.dir/Session.C.o
** Scanning dependencies of target wt
** --
** -- much talking...
** -
** [ 93%] Linking CXX executable test.http
** [ 93%] Building CXX object test/CMakeFiles/test.wt.dir/utf8/XmlTest.C.o
** [ 93%] Built target test.http
** [ 96%] Building CXX object test/CMakeFiles/test.wt.dir/signals/SignalTest.C.o
** [ 96%] Building CXX object test/CMakeFiles/test.wt.dir/wdatetime/WDateTimeTest.C.o
** [ 96%] Building CXX object test/CMakeFiles/test.wt.dir/paintdevice/WRasterTest.C.o
** [ 96%] Linking CXX executable test.wt
** [ 96%] Built target test.wt
** [ 98%] Linking CXX executable test.sqlite3
** [ 98%] Built target test.sqlite3
** [100%] Linking CXX executable test.postgres
** [100%] Built target test.postgres
** \endcode
**
** Now we can install the library.
**
** \code
** mark@lsus1:~/projects/wt/build $ sudo make install
** [sudo] password for serveradmin: 
** [ 74%] Built target wt
** [ 75%] Built target wttest
** [ 80%] Built target wtdbo
** [ 80%] Built target wtdbopostgres
** [ 93%] Built target test.wt
** [ 98%] Built target wthttp
** [100%] Built target test.http
** Install the project...
** -- Install configuration: "RelWithDebInfo"
** -- Up-to-date: /opt/Wt4/share/Wt//resources
** -- Up-to-date: /opt/Wt4/share/Wt//resources/collapse.gif
** --
** -- much talking...
** --
** -- Up-to-date: /opt/Wt4/include/Wt/Render/WTextRenderer.h
** -- Up-to-date: /opt/Wt4/include/Wt/Render/WPdfRenderer.h
** -- Up-to-date: /opt/Wt4/lib/libwthttp.so
** -- Installing: /opt/Wt4/lib/cmake/wt/wt-target-http-relwithdebinfo.cmake
** \endcode
**
**
** Now in the /opt folder should be the Wt folders and files from the installation.
**
** \code
** mark@lsus1:~/projects/wt/build $ ll /opt/Wt4
** total 28
** drwxr-xr-x 7 root root 4096 Oct 11  2017 ./
** drwxrwxr-x 8 root root 4096 May  1 10:56 ../
** drwxr-xr-x 3 root root 4096 Oct 11  2017 etc/
** drwxr-xr-x 3 root root 4096 Oct 11  2017 include/
** drwxr-xr-x 3 root root 4096 May 20 16:14 lib/
** drwxr-xr-x 3 root root 4096 Oct 11  2017 share/
** drwxr-xr-x 3 root root 4096 Oct 11  2017 var/
** \endcode
**
** You now have the Wt library built from source and installed on your
**  system.  You're ready to build your first application.
**
** ### 2. create a project folder
**
** When building Wt project, I like to stick with a fairly straight forward
**  project folder setup.  I keep the build files and source files separated
**  and I use symbolic links to reference the resources folders and whatnot.
**
** \par Make the project folder:
** \code
** mark@lsus1:~/projects $ mkdir demoapp
** mark@lsus1:~/projects $ cd demoapp
** mark@lsus1:~/projects/demoapp $ mkdir src
** mark@lsus1:~/projects/demoapp $ mkdir build
** mark@lsus1:~/projects/demoapp $ cd src
** mark@lsus1:~/projects/demoapp/src $ mkdir docroot
** mark@lsus1:~/projects/demoapp/src $ cd ../build
** mark@lsus1:~/projects/demoapp/build $ ln -s ../src/docroot docroot
** mark@lsus1:~/projects/demoapp/build $ ll
** total 4
** drwxrwxr-x 1 mark mark 14 May 21 06:20 ./
** drwxrwxr-x 1 mark mark 16 May 21 06:20 ../
** lrwxrwxrwx 1 mark mark 14 May 21 06:20 docroot -> ../src/docroot/
** mark@lsus1:~/projects/demoapp/build $ cd ..
** mark@lsus1:~/projects/demoapp $ tree
** .
** ├── build
** │   └── docroot -> ../src/docroot
** └── src
**     └── docroot
**
**     4 directories, 0 files
** \endcode
**
** The 'src' and 'build' folders are pretty straight forward, and fairly common
**  to find in most projects.  But what is the 'docroot' folder?
**
** The 'docroot' folder is the 'web-server-files' folder.  This is the folder
**  that (typically) contains everything the web server is going to 'serve'
**  up to the browser.  Any static html files (such as index.html) and image
**  files are all served from this set of folders.
**
** There is another folder that our webserver is going to be needing.  When we
**  built and installed Wt, the installation included a folder called
**  '/opt/Wt4/share/Wt/resources'.  This folder contains a whole pile of css
**  files and other files that Wt likes to use.  It is not an absolute requirement
**  that the 'resources' folder be available to the Wt server, but when the web
**  pages start to get constructed you'll find that some of the web-page
**  formatting doesn't work without the resources folder.  But, we'll be dealing
**  with that in the next tutorial...
**
**
** ### 3. create project files
**
** There are a few steps here to setting up a new project.  These steps include
**  creating the source file, creating the make file, creating the launch file,
**  and so on.  Hang in there while we work through these.
**
** #### 3.1 create the main.cpp
**
** The main.cpp source file is very simple (for now):
** \code
** mark@lsus1:~/projects/demoapp $ cd src
** mark@lsus1:~/projects/demoapp/src $ cat main.cpp
** #include <Wt/WServer.h>
** int main(int argc, char** argv)
** {
**   try
**   {
**     Wt::WServer server( argc, argv );
**     server.run();
**   }
**   catch( Wt::WServer::Exception & e )
**   {
**     std::cerr << e.what() << std::endl;
**     return -1;
**   }
**   return 0;
** }
** \endcode
**
** #### 3.2 create the 'make' file
**
** Now we need a 'make' file.  The 'make' file contains all the codes
**  necessary for identifying all the source files and library files that
**  are required to get the project built.  I use 'cmake' to generate my
**  make files.
**
** The CMakeLists.txt file is used by cmake to generate the make files for
**  the project.  This file should be placed in the root or the project
**  directory tree:
**
** \code
** mark@lsus1:~/projects/demoapp $ ls -la
** total 4
** drwxrwxr-x 1 mark mark  44 May 21 11:52 .
** drwxrwxr-x 1 mark mark 304 May 21 06:19 ..
** drwxrwxr-x 1 mark mark  14 May 21 06:20 build
** -rw-rw-r-- 1 mark mark 293 May 21 11:52 CMakeLists.txt
** drwxrwxr-x 1 mark mark  14 May 21 06:20 src
** mark@lsus1:~/projects/demoapp $ cat CMakeLists.txt
** cmake_minimum_required (VERSION 2.6)
** set ( CMAKE_CXX_FLAGS "-std=c++17 -Wfatal-errors -g" )
** add_definitions(-std=c++17)
** include_directories(/opt/Wt4/include)
** link_directories(/opt/Wt4/lib)
** project(demoapp)
** add_executable(demoapp src/main.cpp)
** target_link_libraries(demoapp wt wthttp)
** \endcode
**
** This very minimal CMakeLists.txt file contains just enough instruction to
**  be able to compile and link a simple Wt application.  The name of the
**  application is going to be 'demoapp' and it is going to be based on
**  the compiled contents of the main.cpp file found in the 'src' directory.
**  This cmake file also directs where the compiler should go to look for the
**  include files for the Wt installation.
**
** Now it's time to generate the 'make' files inside the 'build' folder
**  and get ready to compile the application.
**
** \code
** mark@lsus1:~/projects/demoapp$ cd build
** mark@lsus1:~/projects/demoapp/build$ cmake ..
** -- The C compiler identification is GNU 5.4.0
** -- The CXX compiler identification is GNU 5.4.0
** -- Check for working C compiler: /usr/bin/cc
** -- Check for working C compiler: /usr/bin/cc -- works
** -- Detecting C compiler ABI info
** -- Detecting C compiler ABI info - done
** -- Detecting C compile features
** -- Detecting C compile features - done
** -- Check for working CXX compiler: /usr/bin/c++
** -- Check for working CXX compiler: /usr/bin/c++ -- works
** -- Detecting CXX compiler ABI info
** -- Detecting CXX compiler ABI info - done
** -- Detecting CXX compile features
** -- Detecting CXX compile features - done
** -- Configuring done
** -- Generating done
** -- Build files have been written to: /home/mark/projects/demoapp/build
** \endcode
**
**
** ...and make it!
**
** \code
** mark@lsus1:~/projects/demoapp/build$ make
** [ 50%] Building CXX object CMakeFiles/demoapp.dir/src/main.cpp.o
** [100%] Linking CXX executable demoapp
** [100%] Built target demoapp
** \endcode
**
**
** If everything worked correctly, you should end up with a handful of files
**  in the build folder, containing a properly (and successfully) compiled
**  executable binary
**
** \code
** mark@lsus1:~/projects/demoapp/build$ ls -la
** total 48
** drwxrwxr-x 1 mark mark   130 May 21 17:52 .
** drwxrwxr-x 1 mark mark    72 May 21 17:48 ..
** -rw-rw-r-- 1 mark mark 11554 May 21 17:48 CMakeCache.txt
** drwxrwxr-x 1 mark mark   388 May 21 17:52 CMakeFiles
** -rw-rw-r-- 1 mark mark  1377 May 21 17:48 cmake_install.cmake
** -rwxrwxr-x 1 mark mark 20392 May 21 17:52 demoapp   <---------------- this is the executable
** lrwxrwxrwx 1 mark mark    14 May 21 06:20 docroot -> ../src/docroot
** -rw-rw-r-- 1 mark mark  4860 May 21 17:48 Makefile
** \endcode
**
**
** Now the server should run.  There are a few command line parameters that
**  are required, I'll go through those one at a time.
**
** \code
** mark@lsus1:~/projects/demoapp/build$ ./demoapp --http-address 0.0.0.0 --http-port 8910 --docroot=docroot
** [2018-May-21 17:57:45.971] 3776 - [info] "config: reading Wt config file: /opt/Wt4/etc/wt/wt_config.xml (location = './demoapp')"
** [2018-May-21 17:57:45.972] 3776 - [info] "WServer/wthttp: initializing built-in wthttpd"
** [2018-May-21 17:57:45.972] 3776 - [info] "wthttp: started server: http://0.0.0.0:8910"
** \endcode
**
** \par http-address
**      this sets the 'listening' address.  If set to 0.0.0.0 then the
**       server will listen on any interface.
**
** \par http-port
**      this sets the listening port.  This has to be a port that is available
**       to an ordinary mortal, unless you plan to run the server as root (bad
**       idea, double-unrecommended)
**
** \par docroot
**      this is the server document root folder.  Files placed in this folder
**       become visible to browsers.
**
** For a complete description on the command line parameters for the Wt server,
**  you can refer to the Wt documentation directly at
**  https://www.webtoolkit.eu/wt/doc/reference/html/InstallationUnix.html
**
** With the server now running, you should be able to browse to it with any
**  browser.  When you do, the server will spit out a handful of messages
**  indicating that it was poked by someone.  If the browser is pointed to
**  http://localhost:8910 you should see a "404 Not Found" message in the
**  browser window.  And this is what you should see on the server:
**
** \code
** mark@lsus1:~/projects/wt/demoapp/build$ ./demoapp --http-port 8910 --http-address 0.0.0.0 --docroot=docroot
** [2018-May-21 18:08:31.729] 10836 - [info] "config: reading Wt config file: /opt/Wt4/etc/wt/wt_config.xml (location = './demoapp')"
** [2018-May-21 18:08:31.730] 10836 - [info] "WServer/wthttp: initializing built-in wthttpd"
** [2018-May-21 18:08:31.730] 10836 - [info] "wthttp: started server: http://0.0.0.0:8910"
** 192.168.1.33 - - [2018-May-21 18:08:39.274] "GET / HTTP/1.1" 404 85   <--------------- note the request, and 404 response
** \endcode
**
**
** If you attempt to call up a file with the browser, you will see something on
**  the order of "404 Not Found" and on the server, you should see the request
**  for the page, and the 404 code that it was not found:
**
** \code
** [2018-May-23 14:22:25.703] 19664 - [info] "config: reading Wt config file: /opt/Wt4/etc/wt/wt_config.xml (location = './demoapp')"
** [2018-May-23 14:22:25.704] 19664 - [info] "WServer/wthttp: initializing built-in wthttpd"
** [2018-May-23 14:22:25.704] 19664 - [info] "wthttp: started server: http://0.0.0.0:8910"
** 192.168.1.33 - - [2018-May-23 14:22:38.776] "GET /testpage.html HTTP/1.1" 404 85    <--------- request for page that doesn't exist
** \endcode
**
** To satisfy the request for a file, it is now a simple matter of
**  adding the file to the 'docroot' folder, and it will be immediately
**  available to the browser:
**
** \code
** mark@lsus1:~/projects/wt/demoapp/build/ $ echo "<html><body>this is a test</body></html>" > docroot/testpage.html
** mark@lsus1:~/projects/wt/demoapp/build$ ./demoapp --http-port 8910 --http-address 0.0.0.0 --docroot=docroot
** [2018-May-23 14:26:24.632] 22345 - [info] "config: reading Wt config file: /opt/Wt4/etc/wt/wt_config.xml (location = './demoapp')"
** [2018-May-23 14:26:24.633] 22345 - [info] "WServer/wthttp: initializing built-in wthttpd"
** [2018-May-23 14:26:24.633] 22345 - [info] "wthttp: started server: http://0.0.0.0:8910"
** 192.168.1.33 - - [2018-May-23 14:26:28.135] "GET /testpage.html HTTP/1.1" 200 41        <------ wholla! file was found, fetched, and displayed!
** \endcode
**
** What happened here is, the WServer engine started up and immediately  created
**  what's called a static "file" resource
**  (<a href="https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WFileResource.html">WFileResource</a>)
**  and directed it to respond to HTTP requests for files located in the docroot
**  folder.  This was automatic and handy because the docroot folder is
**  likely to fill up with all kinds of site-support files, such as static
**  html files and images, and it also is going to contain the Wt 'resources'
**  that contains all the .css formatting files, and the only thing you needed
**  to do to have that happen is specify the docroot folder location.  Pretty
**  sniffty!
**
** So you now have a "static file" web server, in Wt, ready to serve up static files.
**  These files can be of any type, html, binary, pdf... you name it.  But they are
**  static, and, so therefore, you're not really using the "phenominal cosmic powa"
**  of Wt... but, fret not, that's next!
**
** Tune in to \ref active_linux_server to turn this 'static-file' server in to an
**  actual "active" Wt web server with real-live widgets.
**
** \par Notes on cmake and Qt
** \code
** https://blog.kitware.com/cmake-finding-qt5-the-right-way/
** \endcode
*/


/*!
** \page active_linux_server Part 2 ~ Creating an "active" web server with Wt
**
** This document is a continuation of \ref simple_linux_server tutorial.  In that
**  previous tutorial, we downloaded and built the Wt-4 library set, and then built
**  a simple web server capable of serving up simple static web files.
**
** But now we want to develop a 'live' website, and release that phenominal cosmic
**  powa of Wt that reporters are talking about!  This is actually (relatively) fairly
**  simple as well.  Yes, a little more code than before, it not too bad, eh?  Let's
**  get to it!
**
** Back to our main.cpp program file, we're going to add a few lines:
**
** \code
** mark@lsus1:~/projects/demoapp $ cd src
** mark@lsus1:~/projects/demoapp/src $ cat main.cpp
** #include <Wt/WServer.h>
** #include <Wt/WApplication.h>
** #include <Wt/WEnvironment.h>
** #include <Wt/WContainerWidget.h>
** #include <Wt/WText.h>
**
** class DemoApp
** : public Wt::WApplication
** {
**   public:
**     DemoApp(const Wt::WEnvironment &env)
**     : Wt::WApplication( env )
**     {
**       root()-> addNew<Wt::WText>("Hello World!");
**       root()-> addNew<Wt::WBreak>();
**       root()-> addNew<Wt::WText>("It's great to be alive!");
**     }
**
** };
**
** int main(int argc, char** argv)
** {
**   try
**   {
**     Wt::WServer server( argc, argv );
**
**     server.addEntryPoint
**     (
**       Wt::EntryPointType::Application,
**       [](const Wt::WEnvironment &env)
**       {
**         return std::make_unique<DemoApp>(env);
**       },
**       "/site"
**     );
**
**     server.run();
**   }
**   catch( Wt::WServer::Exception & e )
**   {
**     std::cerr << e.what() << std::endl;
**     return -1;
**   }
**
**   return 0;
**
** }
** \endcode
**
** Let's go through this bit by bit.
**
** The first thing to do is sub-class the
**  <a href="https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WApplication.html">WApplication</a>
**  object like this:
**
** \code
** class DemoApp
** : public Wt::WApplication
** {
**   public:
**     DemoApp( const Wt::WEnvironment & env )
**     : Wt::WApplication( env )
**     {
**       root()-> addNew<Wt::WText>("Hello World!");
**       root()-> addNew<Wt::WBreak>();
**       root()-> addNew<Wt::WText>("It's great to be alive!");
**     }
** };
** \endcode
**
** In the constructor of the class we access something called the
**  root() container.  The root() container is actually a
**  <a href="https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WContainerWidget.html">WContainerWidget</a>
**  at the root of the browser window.  It is the base 'div' element
**  in the browser.  So, anything that gets 'added' to the browser
**  window gets added inside that base (root) 'div' element.  In this
**  case we added a WText object to the root() container, and the result
**  should place the text "Hello World!" in the browser window.
**
** Next, in the main() function, where the WServer is being initialized
**  we added an 'entry point' to the WServer so that when a browser hits
**  the server and makes a request, the server knows how to respond.  In
**  this case, if the browser makes the request \b http://localhost:8910/site
**  then the WServer will instantiate a new DemoApp Application class
**  and kick it off.
**
** \code
** server.addEntryPoint
** (
**   Wt::EntryPointType::Application,
**   []( const Wt::WEnvironment &env )
**   {
**     return std::make_unique<DemoApp>(env);
**   },
**   "/site"  <------------- URL designation for this app
** );
** \endcode
**
** Notice that when we create an 'entry point' to the server, we have
**  to give the entry point a 'path'.  In this case I designated the entry
**  point to be "/site" so when that site URL is hit, this specific
**  application class will be brought to life.  There is an issue with
**  this 'path' variable as it pertains to the WFileResouce service that
**  being employed in the previous tutorial, but I'll address that shortly.
**
** \note There is one server 'instance' running at this time, but for
**  every browser 'session' that requests an app there is a newly constructed
**  WApplication object, so therefore, each browser 'session' is running in
**  its own application and is therefore separated from any other running
**  application.  These 'sessions' are available from the
**  <a href="https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WServer.html">WServer</a>
**  object.
**
** When I hit the site from the browser with \b http://localhost:8910/site
**  I can observe the following in the server console:
**
** \code
** mark@lsus1:~/projects/wt/demoapp/build$ ./demoapp --http-port 8910 --http-address 0.0.0.0 --docroot=docroot
** [2018-May-24 07:17:32.522] 641 - [info] "config: reading Wt config file: /opt/Wt4/etc/wt/wt_config.xml (location = './demoapp')"
** [2018-May-24 07:17:32.523] 641 - [info] "WServer/wthttp: initializing built-in wthttpd"
** [2018-May-24 07:17:32.523] 641 - [info] "wthttp: started server: http://0.0.0.0:8910"
** [2018-May-24 07:17:38.306] 641 - [info] "Wt: session created (#sessions = 1)"  <-------------------------------------- BROWSER REQUEST HAPPENED RIGHT HERE
** [2018-May-24 07:17:38.306] 641 [/site Vsg6zSGQEQtYXNAV] [info] "WEnvironment: UserAgent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:58.0) Gecko/20100101 Firefox/58.0"
** 192.168.1.33 - - [2018-May-24 07:17:38.308] "GET /site HTTP/1.1" 200 2221
** [2018-May-24 07:17:38.308] 641 - [info] "WebRequest: took 2.198 ms"
** 192.168.1.33 - - [2018-May-24 07:17:38.392] "GET /site?wtd=Vsg6zSGQEQtYXNAV&request=style&page=1 HTTP/1.1" 200 88
** [2018-May-24 07:17:38.392] 641 - [info] "WebRequest: took 42.774 ms"
** 192.168.1.33 - - [2018-May-24 07:17:38.398] "GET /resources/themes/default/wt.css HTTP/1.1" 404 85 <------------------ NOTE THE 404 FAILURE
** 192.168.1.33 - - [2018-May-24 07:17:38.399] "GET /resources/moz-transitions.css HTTP/1.1" 404 85
** 192.168.1.33 - - [2018-May-24 07:17:38.400] "GET /site?wtd=Vsg6zSGQEQtYXNAV&sid=721053147&webGL=true&scrW=1920&scrH=1080&tz=-300&htmlHistory=true&deployPath=%2Fsite&request=script&rand=17044273 HTTP/1.1" 200 37702
** [2018-May-24 07:17:38.400] 641 - [info] "WebRequest: took 10.169 ms"
** 192.168.1.33 - - [2018-May-24 07:17:38.504] "POST /site?wtd=Vsg6zSGQEQtYXNAV HTTP/1.1" 200 49
** [2018-May-24 07:17:38.504] 641 - [info] "WebRequest: took 0.56 ms"
** \endcode
**
** Hey, now we're cooking with cheese!
**
** The browser should have some text in it, with the words "Hello World! It's great to be alive!".  If you
**  inspect the page, you should see something like this:
**
** \code
** <div id="o27pxbl" class="Wt-domRoot" style="height: 100%;">
**   <div id="Wt-timers" style="position:absolute;height:0.0px;"></div>
**   <div id="o27pxbn" style="height:100.0%;"> <---- THIS IS THE ROOT WCONTAINERWIDGET
**     <span id="o27pxcb"> <------------------------ THIS IS THE WTEXT WIDGET
**       Hello World!
**     </span>
**     <br id="o27pxcc"> <-------------------------- THIS IS THE WBREAK WIDGET
**     <span id="o27pxcd"> <------------------------ THIS IS THE OTHER WTEXT WIDGET
**       It's great to be alive!
**     </span>
**   </div>
**   <div id="o27pxc8" class="Wt-loading" style="display: none;">
**     Loading...
**   </div>
** </div>
** \endcode
**
** Very cool.  Everything appears to be working.  There's quite a bit going on here,
**  so let's look at a few things.
**
** First off, what's happening is the WServer object was given an 'entry point'
**  associated with a URL "/site" such that when that URL was hit, the WServer would
**  create a new WApplication object for it, and allow that WApplication object to
**  serve up the content.  The content that is being served up is just a couple of
**  text messages.
**
** What Wt does is it opens a little conversation with the browser to try to discover
**  what the browser's capabilities are.  If it detects that the browser supports java,
**  then it sends to the browser a little wrapper script to 'contain' the website
**  and turn it in to an AJAX-esque web page, that is live and actively connected
**  back to the server.  The actual web page is then loaded with all the necessary
**  html tags, with ID values embedded such that the browser scripts can access those
**  html tags and update them... dynamically.  This means you can place a
**  WWidget on a web page, and change it's values/contents in C++ and the Wt
**  will automatically propagate those changes right in to the browser, and only update
**  those browser DOM elements that actually need to be updated.  This keeps the
**  interactions between Wt and the browser very short, compact and fast, as the only
**  data moving back and forth is the data required to keep the web page up to date.
**  That's different than most web sites that require a total page refresh to get any
**  updates applied.  This makes Wt able to generate websites that run extremely
**  fast.
**
** Another thing that happens on first session start, that if Wt queries the browser
**  and determines that the browser has limited abilities, or doesn't have the
**  ability to run java or something, then the Wt session will incrementally dumb-down
**  the link between the browser and Wt to the point where if the only thing the browser
**  can handle is straight-basic-html with no scripting and no fancy formatting,
**  then that's what Wt will use... and the web page will still look the same in the
**  dumbed-down browser as it does in the high-tech advanced browser.
**
** Now let's take a look at that 404 failure we saw on the server console.
**
** \code
** [2018-May-24 07:17:38.392] 641 - [info] "WebRequest: took 42.774 ms"
** 192.168.1.33 - - [2018-May-24 07:17:38.398] "GET /resources/themes/default/wt.css HTTP/1.1" 404 85 <-- 404 ERROR
** 192.168.1.33 - - [2018-May-24 07:17:38.399] "GET /resources/moz-transitions.css HTTP/1.1" 404 85 <---- 404 ERROR
** \endcode
**
** This 404 error indicates that the files that were requested by the browser were not
**  able to be located by the server.  In this case, these files are from the 'resources'
**  folder.  The 'resources' folder is the css folder provided by the Wt installation.
**  To fix this all we need to do is link that resources folder in to our 'docroot' folder.
**
** \code
** mark@lsus1:~/projects/wt/demoapp/build$ ln -s /opt/Wt4/share/Wt/resources ../src/docroot/resources
** mark@lsus1:~/projects/wt/demoapp/build$ ./demoapp --http-port 8910 --http-address 0.0.0.0 --docroot=docroot
** [2018-May-25 05:51:39.087] 7255 - [info] "config: reading Wt config file: /opt/Wt4/etc/wt/wt_config.xml (location = './demoapp')"
** [2018-May-25 05:51:39.088] 7255 - [info] "WServer/wthttp: initializing built-in wthttpd"
** [2018-May-25 05:51:39.088] 7255 - [info] "wthttp: started server: http://0.0.0.0:8910"
** [2018-May-25 05:52:23.487] 7255 - [info] "Wt: session created (#sessions = 1)"
** [2018-May-25 05:52:23.488] 7255 [/site eFtk2P4NooA8sNV9] [info] "WEnvironment: UserAgent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:58.0) Gecko/20100101 Firefox/58.0"
** 192.168.1.33 - - [2018-May-25 05:52:23.489] "GET /site HTTP/1.1" 200 2221
** [2018-May-25 05:52:23.489] 7255 - [info] "WebRequest: took 2.216 ms"
** 192.168.1.33 - - [2018-May-25 05:52:23.533] "GET /site?wtd=eFtk2P4NooA8sNV9&request=style&page=1 HTTP/1.1" 200 88
** [2018-May-25 05:52:23.533] 7255 - [info] "WebRequest: took 28.405 ms"
** 192.168.1.33 - - [2018-May-25 05:52:23.535] "GET /resources/themes/default/wt.css HTTP/1.1" 200 20924 <-------------------- NO MORE ERROR
** 192.168.1.33 - - [2018-May-25 05:52:23.537] "GET /resources/moz-transitions.css HTTP/1.1" 200 6277
** 192.168.1.33 - - [2018-May-25 05:52:23.545] "GET /site?wtd=eFtk2P4NooA8sNV9&sid=309821055&webGL=true&scrW=1920&scrH=1080&tz=-300&htmlHistory=true&deployPath=%2Fsite&request=script&rand=903332185 HTTP/1.1" 200 37734
** [2018-May-25 05:52:23.545] 7255 - [info] "WebRequest: took 14.317 ms"
** 192.168.1.33 - - [2018-May-25 05:52:23.634] "POST /site?wtd=eFtk2P4NooA8sNV9 HTTP/1.1" 200 49
** [2018-May-25 05:52:23.634] 7255 - [info] "WebRequest: took 0.434 ms"
** \endcode
**
** That's it!  That's all that's needed to run a live AJAX-esque Wt active website!
**
** For questions, comments, suggestions send email to mark@lorimarksolutions.com
**
**/


/*!
** \page active_linux_with_dbo Part 3 ~ Database Support
**
** Wt makes connecting to a back-end database a breeze. There's a whole pile
**  of objects that makes serializing a c++ class to the back-end database easy,
**  plus there are a whole bunch of views for quickly displaying and editing that
**  data. This is one (of the many) place(s) where Wt shines in its phenominal
**  cosmic power.
**
** Wt has a page for their database-objects module which is a good starting
**  point: https://www.webtoolkit.eu/wt/doc/tutorial/dbo.html
**
** Wtx is designed to enhance the already powerful Dbo/Widget (also known as MVC)
**  library to simplify some of the redundant (see; boring) tasks when it comes
**  to stitching Wt dbo objects to browser GUI objects.
**
** I'll swing back around here and get some more notes on the subject.
**
*/

/*!
** \page active_linux_with_user_auth Part 4 ~ User Authentication
**
** This page discusses the steps necessary to allow users to log in to your
**  webserver. Of course, you can authenticate users to your server in any
**  way you see fit. But Wt has some built-in user authentication resources
**  available that make connecting to multiple user authentication services
**  such as Google and Facebook, so it's possible to have an ID from one of
**  those services provide authentication to your server.
**
** Wt has a page for their authentication module which is a good starting
**  point: https://www.webtoolkit.eu/wt/doc/tutorial/auth.html
**
** I'll swing back around here and get some more notes on the subject.
**
*/


/*!
** \page userbackuprestore Backup User database and restore
**
** this is a page about restoring users
**
** In order to save and restore users between database reloads,
** execute the following script;
**
** \code
** pg_dump --column-inserts -a -t "\"sysAuthIdentity\"" -t "\"sysAuthInfo\"" -t "\"sysAuthToken\"" -t "\"sysUser\"" -f users.sql -U artecams -h 127.0.0.1 -d artecams
** \endcode
**
** This will place the file 'users.sql' in to the folder.  It is then safe to~
** drop the entire database and rebuild it.  Before registering any new users
** in to the system then execute the following;
**
** \code
** developer@rtmus2:~/projects/artecams$ ./psql.sh
** psql (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1))
** SSL connection (protocol: TLSv1.3, cipher: TLS_AES_256_GCM_SHA384, bits: 256, compression: off)
** Type "help" for help.
**
** artecams=> \i users.sql
** \endcode
**
** This will re-import the users from the previously saved sql file.
** All of the users should be able to log in like before.
**
*/


/*!
** \page wlayout_and_wtableview Making WTableView 'fit' with 1000's of records
**
** The WTableView is an excellent component for representing and interacting
**  with huge data sets.  The WTableView will only grab 50 or so items from the
**  database and represent them in the view.  As the user scrolls, the object
**  will grab additional 'pages' of data, and allow the browser to scroll through
**  them fluidly.
**
** \image html WLayout_WTableView.png
**
** The trick to getting this to work properly is to make sure that the WTableView
**  knows the height of the browser.  This is more difficult that one might
**  expect.  (when one says 'one' substitute; 'author').  This is especially difficult
**  with advanced websites with lots of objects (widgets) and views and layouts.
**
** The trick is to use the WLayout managers.  The key to using these managers is
**  to insure that 'every' div element down to the root() element has a layout
**  manager assigned to it.  This is especially tricky on complex websites
**  with lots of different widgets.
**
** There's a problem though;
**
** https://redmine.webtoolkit.eu/boards/2/topics/15120
**
** The new Wt-4 uses 'flex' as the default layout manager, and 'flex' causes the WTableView
**  indigestion.  So it is important to swtich back to the java-based layout
**  management.
**
** The switch to 'java' as the layout manager is supposed to be done at main.cpp
**  prior to anything else inside Wt getting initialized.  You can read about that
**  here: https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WLayout.html and look
**  for 'setDefaultImplementation'.
**
** This is how I do it in my projects:
**
** \par initialize WLayout to 'java'
** \code
** int main(int argc, char** argv)
** {
**   Wt::WLayout::setDefaultImplementation( Wt::LayoutImplementation::JavaScript );
**
**   try
**   {
**     Wt::WServer server( argc, argv );
**
**     Wtx::Sys::Auth::configure();
** \endcode
**
*/









/*!
** \page appnotify Exceptions Notification
**
** During the course of development, Wt will throw exceptions under various conditions.
**  It is exceedingly helpful to know what the exceptions are and at what point
**  they occurred.  It is possible to hook in to the main application loop to catch
**  the exceptions and print a diagnostic.
**
** The documentation for the hook can be found here (link may be out of date):
**
** https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WApplication.html#a4a6f167bea94aefa8ba24f914c2fbee5
**
** Set up the following in your main application class
**
** \par Hooking Application Notification
** \code
** void BaseApp::notify( const Wt::WEvent & event )
** {
**   /*
**   ** Build a list of expected exceptions.  One in particular is if
**   **  the client browser session times-out.  This will cause the
**   **  session to be killed automatically by Wt.  This is an expected
**   **  exception, so it goes on the list of exceptions to the exceptions.
**   **
**   */
**   static std::vector<std::string> exceptions =
**   {
**     "session was killed",
**     "all threads are busy"
**   };
**
**   static std::vector<std::string> pop_exceptions =
**   {
**     "basic_string::at: __n", // this happens when a <space> is put after the time in a WTimeEdit field
**     "bad lexical cast"       // this happens when a '' nothing character is put where a number '0' is expected
**   };
**
**   /*
**   ** Try to notify the main application loop.
**   */
**   try
**   {
**     Wt::WApplication::notify(event);
**   }
**
**   /*
**   ** Handle the application exception.
**   */
**   catch( std::exception & exception )
**   {
**     /*
**     ** If this is an expected exception, then ignore it.  It just means
**     **  it's a dead session, that we don't really care about.
**     */
**     for( auto except : exceptions )
**       if( std::string(exception.what()).find(except) != std::string::npos )
**       {
**         COUT_( "redirecting to: " + originalUrl( internalPath() ) );
**         redirect( originalUrl( internalPath() ) );
**         quit();
**
**         return;
**       }
**
**     /*
**     ** prepare a message that we can send to the logs
**     **
**     */
**     auto message =
**       Wt::WString("EXCEPTION: '{1}'")
**       .arg( exception.what() )
**       .toUTF8()
**       ;
**
**     /*
**     ** Log the exception, and display it to the console as well.
**     **  Note that if you also are logging field-level-changes and
**     **  during one of those changes an exception is thrown, then
**     **  even if the exception does not reveal much about what
**     **  the source of the failure was, the log may contain everything
**     **  that was going on right before the exception was thrown.
**     **
**     */
**     txtLog( message, true );
**
**     /*
**     ** This may be an exception that we just want to pop-up
**     **  to the user.
**     **
**     */
**     for( auto except : pop_exceptions )
**       if( std::string(exception.what()).find(except) != std::string::npos )
**       {
**         Wt::WMessageBox::show
**         (
**           "Exception",
**           "<center>"
**           "  Oh oh, something went wrong,<br />"
**           "  please check what you are editing "
**           "  and try again"
**           "</center>"
**           , Wt::Ok
**         );
**
**         return;
**       }
**
**    COUT_( "\n\n\n\n\n\n<<<<< EXCEPTION >>>>>>>" );
**    COUT_( exception.what() );
**
**    /*
**    ** This exception was not expected, so send a text message to an administrator
**    **  that can hopefully deal with it.
**    **
**    */
**    auto result =
**      system
**      (
**        emailText
**        (
**          "exception",
**          message,
**          {"adminemail@somesuchthing.com"}
**        ).c_str()
**      );
**      (void)result;
**
**     /*
**     ** since this is a fatal exception, just refresh the app so that
**     **  everything properly reloads.
**     **
**     */
**     COUT_( "redirecting to: " + originalUrl( internalPath() ) );
**     redirect( originalUrl( internalPath() ) );
**     quit();
**
**   } // endcatch( std::exception & exception )
**
** } // endvoid CCB::BaseApp::notify( const Wt::WEvent & event )
** \endcode
**
*/


/*!
** \page domtree Rutin to log the actual widget tree
**
** Reprinted with permission: https://redmine.emweb.be/boards/1/topics/14570
**
** Added by Tibor Peak
**
** I just share these routines that I use for debugging purposes:
**
** The first is to show the widget variable name on the GUI when mouse pointer is hold over a widget:
**
** \code
** #define DebugTooltip(vName) vName->setAttributeValue("title",#vName)
**
** void myApplication::AddWidgetStructureDebugTitles(){
**   DebugTooltip(firstLine_CW);
**   DebugTooltip(secondLine_CW);
**   DebugTooltip(siaLogo_Img);
**   // .......
**   DebugTooltip(Feedback_OMF);
** }
** \endcode
**
** The second routine logs the widget tree structure (starting with the widget received as a parameter),
**  using the title attributes set by the previous routine:
**
**
** \code
** void myApplication::ListWidgets(WWebWidget *startPoint, long Counter){
**   WWebWidget      *thisWebWidget;
**   WTabWidget      *thisTabWidget;
**   std::string      thisTypeName;
**   std::string      thisMessage;
**   std::string      spaces("                                                "); // 48 space chars
**   char             Buf[17];
**   std::vector< WWidget * > WidgetList;
**   WidgetList = startPoint->children();
**   for (vector<WWidget *>::iterator it = WidgetList.begin(); it != WidgetList.end(); ++it) {
**     thisWebWidget = (WWebWidget *)*it;
**     thisTypeName = typeid(*thisWebWidget).name();
**     sprintf(Buf,"%02ld",Counter);
**     thisMessage = Buf + (string)". " + spaces.substr(0, (Counter - 1) * 2) + thisTypeName;
**     thisMessage = thisMessage + spaces.substr(0, max(1, (40 - thisMessage.length())));
**     if (thisTypeName == "class Wt::WTabWidget") {
**       thisTabWidget = (WTabWidget *)*it;
**       wApp->log("Info:") << thisMessage << " / " << thisTabWidget->attributeValue("title");
**       short tabCount = thisTabWidget->count();
**       for (short i = 0; i < tabCount; i++) {
**         thisWebWidget = (WWebWidget *)(thisTabWidget->widget(i));
**         thisTypeName = typeid(*thisWebWidget).name();
**         thisMessage = Buf + (string)". " + spaces.substr(0, (Counter - 1) * 2) + thisTypeName;
**         thisMessage = thisMessage + spaces.substr(0, max(1, (40 - thisMessage.length())));
**         wApp->log("Info:") << thisMessage << " / " << thisWebWidget->attributeValue("title");
**         if (thisWebWidget->children().size() > 0) {
**           ListWidgets(thisWebWidget, Counter + 1);
**         }
**       }
**     } else {
**       wApp->log("Info:") << thisMessage << " / " << thisWebWidget->attributeValue("title");
**       if (thisWebWidget->children().size() > 0) {
**         ListWidgets(thisWebWidget, Counter + 1);
**       }
**     }
**   }
** }
** \endcode
**
** Feel free to use it.
**
*/

/*!
** \page debugging Tips and Tricks for Debugging Wt apps
**
** For one, check out the \ref appnotify method of hooking the event
**  handler in the main Wt control loop.  That little technique goes
**  a long way towards letting you know when bad things happen in your
**  app.
**
** In the event you get a std::exception with no explanation, then
**  what you can do is run your application with gdb, and when you
**  do so, there are a couple of commands you can execute before running
**  the application that will catch a throw and show you what was happening
**  right up before the throw.
**
** The following commands came from this blog post on stack overflow:
**
**  https://stackoverflow.com/questions/2443135/how-do-i-find-where-an-exception-was-thrown-in-c
**
** \par Excerpt from stackoverflow
** \code
**
** As you say, we can use 'catch throw' in gdb and call 'backtrace' for every single
**  thrown exception. While that's usually too tedious to do manually, gdb allows
**  automation of the process. That allows seeing the backtrace of all exceptions
**  that are thrown, including the last uncaught one:
**
** gdb>
**
** set pagination off
** catch throw
** commands
** backtrace
** continue
** end
** run
**
** Without further manual intervention, this generates lots of backtraces, including
**  one for the last uncaught exception:
** \endcode
**
** This little gem is super handy, because you can just let your app run, and when
**  it throws, gdb will immediately spit out a back-trace, and will (probably) take
**  you straight to the offender.
**
**
*/

/*!
** \page stringbind Binding Variables to Strings
**
** There are a couple handy methods for quickly formatting
**  strings using the WString and WTemplate objects.  When
**  formatting a simple small string with just a few
**  parameters, then this function works real well:
**
** \code
**  64   auto posggres_connect =
**  65     Wt::WString("host={1} port={2} dbname={3} user={4} password={5}")
**  66     .arg( "localhost"   )
**  67     .arg( 5433          )
**  68     .arg( "tradewindb"  )
**  69     .arg( "twdb"        )
**  70     .arg( "xFoElc442!!" )
**  71     .toUTF8()
**  72     ;·
** \endcode
**
** That formats the string exactly how you want it, and the source
**  is super readable and therefore easy to maintain.  The function
**  converts argument types of strings and integers and doubles alike.
**  This is good for simple 1-line formatted strings.
**
** If the string is longer and more complex then it is useful to
**  employ named placeholders.  That will require the use of the built-in
**  WTemplate object.  Given the following formatted string, put placeholders
**  everywhere there should be a bound string variable:
**
** \code
**   <message id="cbc.pull_request">
**     <data_area>
**       <header_data>
**         <user_id>${user_id}</user_id>
**         <user_pwd>${user_password}</user_pwd>
**         <cus_id>${customer_id}</cus_id>
**         <xml_format>1</xml_format>
**         <action>${bureau_action}</action>
**       </header_data>
**       <applicant_data>
**         <applicant type="primary">
**           <person_name>
**             <first_name>${first_name}</first_name>
**             <middle_name>${middle_name}</middle_name>
**             <last_name>${last_name}</last_name>
**           </person_name>
**           <address_data>
**             <address type="current">
**               <line_one>${street_address}</line_one>
**               <city>${city}</city>
**               <state_or_province>${state}</state_or_province>
**               <postal_code>${zipcode}</postal_code>
**             </address>
**           </address_data>
**           <social>${social_security_number}</social>
**         </applicant>
**       </applicant_data>
**     </data_area>
**   </message>
** \endcode
**
** Using the following procedure, load the formatted string in to the
**  WTemplate object, bind the string values, and then extract the
**  formatted HTML using the 'htmlText' function call.
**
** \code
**   Wt::WTemplate templt( Wt::WString::tr("cbc.pull_request")    );
**   templt.bindString( "user_id",                "Ben"           );
**   templt.bindString( "user_password",          "ABC123!!"      );
**   templt.bindString( "customer_id",            "421123"        );
**   templt.bindString( "bureau_action",          "softpull"      );
**   templt.bindString( "first_name",             "John"          );
**   templt.bindString( "middle_name",            ""              );
**   templt.bindString( "last_name",              "Smith"         );
**   templt.bindString( "street_address",         "123 W. Ave M"  );
**   templt.bindString( "city",                   "Bigtown"       );
**   templt.bindString( "state",                  "Bigstate"      );
**   templt.bindString( "zipcode",                "50505"         );
**   templt.bindString( "social_security_number", "123-45-6789"   );
**
**   std::stringstream ss;
**   templt.htmlText( ss );
**
**   COUT_( ss.str() );
** \endcode
**
** Will produce the following result:
**
** \code
**    <div id="otojh9a">
**      <data_area>
**        <header_data>
**          <user_id>Jim</user_id>
**          <user_pwd>Password1!!</user_pwd>
**          <cus_id>CL14124</cus_id>
**          <xml_format>1</xml_format>
**          <action>softpull</action>
**        </header_data>
**        <applicant_data>
**          <applicant type="primary">
**            <person_name>
**              <first_name>John</first_name>
**              <middle_name></middle_name>
**              <last_name>Smith</last_name>
**            </person_name>
**            <address_data>
**              <address type="current">
**                <line_one>123 West St</line_one>
**                <city>Bigtown</city>
**                <state_or_province>Montanna</state_or_province>
**                <postal_code>50424</postal_code>
**              </address>
**            </address_data>
**            <social>123-45-6789</social>
**          </applicant>
**        </applicant_data>
**      </data_area>
**    </div>
** \endcode
**
** Note that this is simple string binding.  Note also that the resulting
**  'string' also includes html tags <div> at the top and bottom of the
**  output string, so if those are not wanted (they probably arent) then
**  those are going to have to get removed.  But, if you _do_ need to
**  format an html-compliant string, this is a fast way to do it.
**
*/

/*!
** \page dbase Drivers for dBase or Foxpro database files
**
** This is a library that can be used to access and manipulate
**  dBase or Foxpro files:
**
** https://sourceforge.net/projects/xdb/
**
** http://linux.techass.com/projects/xdb/
**
** http://linux.techass.com/projects/xdb/xbasedocs/xbase_toc.html
**
** In case those web pages disappear, there is an archived copy
**  of the site here:
**
** https://support.lorimarksolutions.com/xdb/
**
**
*/

/*!
** \page layouts How to properly build and manage layouts
**
** This is my nemesis... help!
**
** https://redmine.webtoolkit.eu/boards/2/topics/15120?r=15121
**
*/

/*!
** \page monit Using 'monit' to keep your server running
**
** \par Monit lines (for process charts.wt listening on port 1417):
** \code
**   check process charts.wt
**     with pidfile /home/wt/project/wt-deployed/run/charts.wt.pid
**     start program = "/home/wt/project/wthttpd.sh start /home/wt/project/wt-deployed/charts/charts.wt /charts.wt 1417"
**     stop program  = "/home/wt/project/wthttpd.sh stop  /home/wt/project/wt-deployed/charts/charts.wt"
**     if failed port 1417 protocol http request /monittoken then restart
** \endcode
**
** \par wthttpd.sh script:
** \code
** #!/bin/bash
**
** if [ $# '<' "2" ]; then
**   echo $"Usage: wthttpd.sh {start|stop} /path/to/app.wt ..."
**   exit 1
** fi
**
** if [ ! -f $2 ]; then
**   echo $"Could not locate application: $2"; 
**   exit 1
** fi
**
** exe=`basename $2`
** dir=`dirname $2`
** exname=`basename $dir`
**
** export APPROOT=/home/wt/project/approot
** export LD_LIBRARY_PATH=/usr/local/lib
** export PATH=/usr/local/bin:$PATH
** #export MALLOC_CHECK_=2
**
** case "$1" in
**   start)
**     if [ $# != "4" ]; then
**       echo $"Usage: wthttpd.sh start /path/to/app.wt path port"
**       exit 1
**     fi
**
**     cd $dir;
**     touch docroot/monittoken;
**     ulimit -c unlimited;
**     ulimit -s 1024;
**     ./$exe -p ../run/$exe.pid --deploy-path $3 --http-port $4 \
**       --docroot 'docroot;/css,/resources,/icons,/favicon.ico' \
**       --approot $APPROOT/$exname `cat argv` >> ../run/$exe.log 2>&1 &
**     sleep 1;
**     ;;
**
**   stop)
**     if [ $# != "2" ]; then
**       echo $"Usage: wthttpd.sh stop /path/to/app.wt"
**       exit 1
**     fi
**
**     cd $dir;
**     pid=`cat ../run/$exe.pid`;
**     kill $pid;
**     sleep 3;
**     kill -9 $pid;
**     sleep 1;
**     ;;
**
**   *)
**     echo $"Usage: wthttpd.sh {start|stop} /path/to/app.wt ..."
**     exit 1
** esac
** \endcode
**
**
*/

/*!
** \page authentication User Authentication
**
** This is the user authentication system
**
** Reference: https://www.webtoolkit.eu/wt/doc/tutorial/auth.html
**
** User authentication is handled by three internal Wt tables with an additional
**  application-supplied User table.
**
** \dot
** digraph sysauth
** {
**   AuthIdentityType  [ URL="\ref" label="AuthIdentityType\n(login name)" ];
**   AuthInfo          [ URL="\ref" label="AuthInfo\n(password)"           ];
**   AuthTokenType     [ URL="\ref" label="AuthTokenType\n(rememberMe)"    ];
**   AuthUser          [ URL="\ref" label="AuthUser\n(my app user)"        ];
**
**   AuthIdentityType -> AuthInfo;
**   AuthTokenType -> AuthInfo;
**   AuthInfo -> AuthUser;
**
** }
** \enddot
**
** To manually verify an email login, execute the following;
**
** \code
** livesite# update "sysAuthInfo" set
**             email='user@email.addy',
**             unverified_email='',
**             email_token='',
**             email_token_expires=null,
**             email_token_role=1
**             where id={id-of-item};
** \endcode
**
**
**
** \par Auth Identity Type
** \code
** livesite# \d "sysAuthIdentityType";
**                                      Table "public.sysAuthIdentityType"
**          Column     |          Type          |                             Modifiers
**     ----------------+------------------------+--------------------------------------------------------------------
**      id             | bigint                 | not null default nextval('"sysAuthIdentityType_id_seq"'::regclass)
**      version        | integer                | not null
**      sysAuthInfo_id | bigint                 |
**      provider       | character varying(64)  | not null
**      identity       | character varying(512) | not null
**     Indexes:
**         "sysAuthIdentityType_pkey" PRIMARY KEY, btree (id)
**     Foreign-key constraints:
**         "fk_sysAuthIdentityType_sysAuthInfo" FOREIGN KEY ("sysAuthInfo_id") REFERENCES "sysAuthInfo"(id) ON DELETE CASCADE DEFERRABLE INITIALLY DEFERRED
** \endcode
**
**
**
** \par Auth Token Type
** \code
** livesite# \d "sysAuthTokenType";
**                                      Table "public.sysAuthTokenType"
**          Column     |            Type             |                            Modifiers
**     ----------------+-----------------------------+-----------------------------------------------------------------
**      id             | bigint                      | not null default nextval('"sysAuthTokenType_id_seq"'::regclass)
**      version        | integer                     | not null
**      sysAuthInfo_id | bigint                      |
**      value          | character varying(64)       | not null
**      expires        | timestamp without time zone |
**     Indexes:
**         "sysAuthTokenType_pkey" PRIMARY KEY, btree (id)
**     Foreign-key constraints:
**         "fk_sysAuthTokenType_sysAuthInfo" FOREIGN KEY ("sysAuthInfo_id") REFERENCES "sysAuthInfo"(id) ON DELETE CASCADE DEFERRABLE INITIALLY DEFERRED
** \endcode
**
**
**
** \par Auth Info Table
** \code
** livesite# \d "sysAuthInfo"
**                                              Table "public.sysAuthInfo"
**          Column         |            Type             |                         Modifiers
**  -----------------------+-----------------------------+------------------------------------------------------------
**   id                    | bigint                      | not null default nextval('"sysAuthInfo_id_seq"'::regclass)
**   version               | integer                     | not null
**   user_id               | bigint                      |
**   password_hash         | character varying(100)      | not null
**   password_method       | character varying(20)       | not null
**   password_salt         | character varying(20)       | not null
**   status                | integer                     | not null
**   failed_login_attempts | integer                     | not null
**   last_login_attempt    | timestamp without time zone |
**   email                 | character varying(256)      | not null
**   unverified_email      | character varying(256)      | not null
**   email_token           | character varying(64)       | not null
**   email_token_expires   | timestamp without time zone |
**   email_token_role      | integer                     | not null
**  Indexes:
**      "sysAuthInfo_pkey" PRIMARY KEY, btree (id)
**  Foreign-key constraints:
**      "fk_sysAuthInfo_user" FOREIGN KEY (user_id) REFERENCES "sysAuthUser"(id) ON DELETE CASCADE DEFERRABLE INITIALLY DEFERRED
**  Referenced by:
**      TABLE ""sysAuthIdentityType"" CONSTRAINT "fk_sysAuthIdentityType_sysAuthInfo" FOREIGN KEY ("sysAuthInfo_id") REFERENCES "sysAuthInfo"(id) ON DELETE CASCADE DEFERRABLE INITIALLY DEFERRED
**      TABLE ""sysAuthTokenType"" CONSTRAINT "fk_sysAuthTokenType_sysAuthInfo" FOREIGN KEY ("sysAuthInfo_id") REFERENCES "sysAuthInfo"(id) ON DELETE CASCADE DEFERRABLE INITIALLY DEFERRED
** \endcode
**
**
** \par Auth User Table
** \code
**                                     Table "public.sysAuthUser"
**         Column        |            Type             |                         Modifiers
**  ---------------------+-----------------------------+------------------------------------------------------------
**   id                  | bigint                      | not null default nextval('"sysAuthUser_id_seq"'::regclass)
**   version             | integer                     | not null
**   isActive            | boolean                     | not null
**   isVisible           | boolean                     | not null
**   isDeleted           | boolean                     | not null
**   keyField            | character varying(250)      | not null
**   cfyField            | character varying(80)       | not null
**   varField            | text                        | not null
**   createdOn           | timestamp without time zone |
**   changedOn           | timestamp without time zone |
**   firstName           | text                        | not null
**   lastName            | text                        | not null
**   favouritePet        | text                        | not null
**   userRole_id         | bigint                      |
**   primary_sysGroup_id | bigint                      |
**  Indexes:
**   "sysAuthUser_pkey" PRIMARY KEY, btree (id)
**  Foreign-key constraints:
**   "fk_sysAuthUser_primary_sysGroup" FOREIGN KEY ("primary_sysGroup_id") REFERENCES "sysGroup"(id)    DEFERRABLE INITIALLY DEFERRED
**   "fk_sysAuthUser_userRole"         FOREIGN KEY ("userRole_id")         REFERENCES "sysUserRole"(id) DEFERRABLE INITIALLY DEFERRED
**  Referenced by:
**   TABLE ""crmActivity""     CONSTRAINT "fk_crmActivity_changedBy_sysUser" FOREIGN KEY ("changedBy_sysUser_id") REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""crmActivity""     CONSTRAINT "fk_crmActivity_createdBy_sysUser" FOREIGN KEY ("createdBy_sysUser_id") REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""crmActivity""     CONSTRAINT "fk_crmActivity_p_sysUser"         FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""crmAddress""      CONSTRAINT "fk_crmAddress_p_sysUser"          FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""crmCompany""      CONSTRAINT "fk_crmCompany_p_sysUser"          FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""crmContact""      CONSTRAINT "fk_crmContact_p_sysUser"          FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""crmPerson""       CONSTRAINT "fk_crmPerson_p_sysUser"           FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""fmsAccount""      CONSTRAINT "fk_fmsAccount_p_sysUser"          FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""fmsBatch""        CONSTRAINT "fk_fmsBatch_p_sysUser"            FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""fmsInvoice""      CONSTRAINT "fk_fmsInvoice_p_sysUser"          FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""fmsInvoice""      CONSTRAINT "fk_fmsInvoice_rep_sysUser"        FOREIGN KEY ("rep_sysUser_id") REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""fmsPayDevice""    CONSTRAINT "fk_fmsPayDevice_p_sysUser"        FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""fmsSubscription"" CONSTRAINT "fk_fmsSubscription_p_sysUser"     FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""fmsTransaction""  CONSTRAINT "fk_fmsTransaction_p_sysUser"      FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""mktCampaign""     CONSTRAINT "fk_mktCampaign_p_sysUser"         FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""mktReferrer""     CONSTRAINT "fk_mktReferrer_p_sysUser"         FOREIGN KEY ("p_sysUser_id")   REFERENCES "sysAuthUser"(id) DEFERRABLE INITIALLY DEFERRED
**   TABLE ""sysAuthInfo""     CONSTRAINT "fk_sysAuthInfo_user"              FOREIGN KEY (user_id)          REFERENCES "sysAuthUser"(id) ON DELETE CASCADE DEFERRABLE INITIALLY DEFERRED
** \endcode
**
**
*/

/*!
** \page mobile_friendly Building a mobile-friendly website
**
** One of the challenges for mobile-friendly websites is developing a website that
**  looks good both on a mobile device that it does on a desk-top browser.  I've
**  found this to be a little bit challenging, but there are some techniques to
**  employ that make the task somewhat seamless.
**
** One thing to note before venturing in to this area, is that some WWidget objects
**  do not lend themselves to mobile interfaces.  It's not so much the issue of the
**  'layout' and sizing and presentation, but it's the 'interaction' that can be
**  a challenge for some widgets.  This is true in the case of the WTableView widget
**  which makes really nice scrollable table-views.  But, one of the 'interactions'
**  with the table is the double-click, which can be used to trigger an 'open event'
**  much like what is often done on a PC desktop using a mouse.  On mobile devices
**  properly detecting a double-click by the user is more difficult that you
**  probably want it to be.  So, in the case of mobile-friendly websites, be prepared
**  to employ different controls.
**
** Another thing to consider is being able to control which keyboard is going to be
**  used for any field-input functions.  Most mobile devices support multiple different
**  styles of keyboards, such as a phone-dialer keyboard which dialing phone numbers,
**  and a email-layout keyboard for inputting entries on fields that are asking for
**  email addresses... you can control which keyboard will be displayed by the mobile
**  device by setting a few different attributes in your input fields.
**
** \par Modify wt_config.xml
** \code
** <meta-headers user-agent=".*">
**  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
** </meta-headers>
** \endcode
**
** These codes cause this meta-header to be placed at the top of each web-page to
**  the browser, and this allows mobile devices to properly display web pages sized
**  for their browser window.  Try formatting a simple .html web page a adding
**  and removing these codes from the header, and see how it affects your cell-phone
**  page display:
**
** \code
**  <html>
**    <head>
**      <meta name="viewport" content="width=device-width, initial-scale=1.0" />
** \endcode
**
** Mobile devices also have the ability to respond to 'suggestions' regarding which
**  keyboard should be loaded.  These are explained here: https://html.spec.whatwg.org/multipage/input.html#attr-input-type
**  In order to get Wt to 'push' these suggestions to the mobile device, the
**  input-widgets can be plugged with these values.  The following code will cause
**  a mobile device to use the 'datetime' input keyboard for this particular input
**  field;
**
** \code
** auto start = templt-> bindNew<Wt::WLineEdit>("start");
** start-> setAttributeValue( "type", "datetime" );   // set 'datetime' keyboard type
** \endcode
**
**/

/*!
** \page sampleui Sample User Interfaces with Wt
**
** The following are some samples of UI's built with Wt:
**
** \par Two Linked Table Views with slider-divider
** \image html wt-sample-ui-table-views-linked.png
**
** \par A Detail Form loaded from a Table View
** \image html wt-sample-ui-detail-form.png
**
** \par A Hard-Drive explorer
** \image html wt-sample-ui-hard-drive-explorer.png
**
**
*/

/*!
** \page newwtx How to make a new Wtx Dbo site
**
** Steps to building a new table with Wtx;
**
** -# create Definition.h
** -# create Template.h
** -# create Item.h/cpp
**
** The purpose of Item.cpp is to simply create the actual database
**  'item' since the Template doesn't have enough of a shell to
**  hold anything, it's just a suggestion of a class and it's content.
**  the item.cpp device actually brings the template in to being.
**  The reason the item and the template are separated, is because
**  if the system needs to be expanded in any way, the expansion 
**  occurs from the template.  This renders the item.cpp content
**  down to a simple place holder for the dbo objects.
**
**/

/*!
** \page comboboxmodel Make a ComboBox model with a blank item
**
** Sometimes you want to populate a combo box from another table.  This
**  is all well and good when you want to pick from a list of items
**  populated from a table, but what if you want to also be able to
**  select "no" item, or otherwise deselect any current selections?
**  When populating a combo box from a model, the combo box will only
**  allow a selection from the list.  Therefore, it is necessary
**  to create a model that has an extra blank item.
**
** This is very easy to do with a direct SQL statement.
**
** \code
**    97 std::shared_ptr<Wt::WAbstractItemModel> Mrp::Company::getComboBoxModel( int sid, int tid, const std::string & where, Wtx::Dbo::Session & session )
**    98 {
**    99   auto retVal = std::make_shared< Wtx::Dbo::QueryModel< std::tuple<int,std::string> > >();
**   100
**   107   Wt::Dbo::Transaction t(session);
**   108
**   109 //  auto w = where;
**   110 //  if( tid != -1 )
**   111 //    w = Wt::WString("WHERE id={1}").arg(tid).toUTF8();
**   112
**   113   auto sql =
**   114     Wt::WString
**   115     (
**   116      "SELECT id,\"keyField\" || ' ~ ' || \"cfyField\" AS key FROM \"crmCompany\""
**   117      " {1}"
**   118      " UNION "
**   119      "SELECT -1 as id, '' as key"
**   120      " ORDER BY key"
**   121     )
**   122     .arg( where )
**   123     .toUTF8()
**   124     ;
**   125
**   126
**   127   auto query =
**   128    session.query< std::tuple<int,std::string> >( sql )
**   129    ;
**   130
**   131   retVal-> setQuery( query );
**   132   retVal-> addColumn("id");
**   133   retVal-> addColumn("key");
**   134
**   135   return retVal;
**   136 }
** \endcode
**
**
*/

/*!
** \page remote_foreign_db How to connect Wt-on-Linux to a MSSQL-on-Windows database server
**
** This article describes the steps necessary for connecting to a remote
**  MSSQL database server, from a Wt application that has been compiled
**  and is running on a linux box.
**
** \note This procedure is brand-new (to me) and so these steps are not
**        fully developed and documented yet.  Use with caution.
**
** - The steps encompass the following;
**  -# Install ODBC driver on Linux
**  -# Create a Session Connection string
**  -# Create a database Table dbo class
**  -# Create a Table View of the data
**
** ### Install the ODBC driver
**
** There are a few steps involved in installing the ODBC driver.  There is
**  an ODBC driver from microsoft, and then there is an additional tool
**  called 'FreeTDS' which is an additional wrapper to the microsoft driver.
**  I am unclear (at this time) as to the relationship between the FreeTDS
**  and the MS-ODBC.
**
** - Follow the procedure here to install the ODBC driver
**  -# https://docs.microsoft.com/en-us/sql/connect/odbc/linux-mac/installing-the-microsoft-odbc-driver-for-sql-server?view=sql-server-2017
**
** ### Create a Session Connection string
**
** The session connection string can be employed a couple of different ways;
**  by DSN values or by DIRECT values.  Either can work but I think it might
**  be a little more convenient for start-up systems to simply employ the
**  DIRECT connection string.  I'll show both here;
**
** \par Connection String Methods
** \code
**  250 #ifdef WTX_USING_MSSQL
**  251 #ifdef USING_DSN_STRING
**  252   auto dbName =
**  253     Wt::WString( "DSN={1};UID={2};PWD={3}" )
**  254     .arg( "dbname" )
**  255     .arg( "username" )
**  256     .arg( "password" )
**  257     .toUTF8()
**  258     ;
**  259 #else
**  260   auto dbName =
**  261     Wt::WString( "Driver={1};Server={2};UID={3};PWD={4};Database={5};" )
**  262     .arg( "{ODBC Driver 17 for SQL Server}" ) // set to your proper ODBC installation version
**  263     .arg( "servername_or_ip"                )
**  264     .arg( "username"                        )
**  265     .arg( "password"                        )
**  266     .arg( "dbname"                          )
**  267     .toUTF8()
**  268     ;
**  269 #endif
**  270
**  271   auto connection =
**  272     std::make_unique<Wt::Dbo::backend::MSSQLServer>( dbName );
**  273 #endif
**  274
** \endcode
**
** This will open a session to the database, regardless of where the database is located, either on
**  the localhost or on a remote-ip address, it doesn't matter.  As long as you have the credentials
**  correct, and you can get to the server you're good to go!
**
** ### Create a database Table dbo class
**
** In order to "talk" to the database and bring data in to the application so as to be able to
**  represent it in a browser, a class-object must be create to contain the database record information.
**  This is quite easy to do, simply by defining a class with the necessary storage fields, and then
**  providing in that class a hook for the dbo connections.
**
**
** \par DBO Class Definition
** \code
**  149 //
**  150 // predefine the 'Entity' class
**  151 //
**  152 namespace Coy {
**  153 class Entity;
**  154 }
**  155
**  156 //
**  157 // Wt provides for optimistic record-locking through the use
**  158 //  of a 'version' field on each record.  This code causes that
**  159 //  feature to be disabled, since we cannot modify the schema
**  160 //  of this foreign database.
**  161 //
**  162 //
**  163 namespace Wt {
**  164   namespace Dbo {
**  165     template<>
**  166     struct dbo_traits<Coy::Entity> : public dbo_default_traits
**  167     {
**  168       static const char * versionField()
**  169       {
**  170         return nullptr;
**  171       }
**  172     };
**  173   } // endnamespace Dbo
**  174 } // endnamespace Wt
**  175
**  176 //
**  177 // Create an 'Entity' class for holding the database record
**  178 //  information
**  179 //
**  180 namespace Coy {
**  181 class Entity
**  182 : public Wt::Dbo::Dbo<Entity>
**  183 {
**  184   public:
**  185
**  186     Entity();
**  187
**  188     template<class Action> void persist( Action &a )
**  189     {
**  190
**  191       Wt::Dbo::field( a, code,                 "code"                 );
**  192       Wt::Dbo::field( a, description,          "description"          );
**  193       Wt::Dbo::field( a, typeID,               "typeID"               );
**  194
**  195     }
**  196
**  197     std::string code;
**  198     std::string description;
**  199     int typeID;
**  200
**  201 }; // endclass Entity
**  202 } // endnamespace Coy {
**  203
** \endcode
**
** With this class, it is now possible for us to 'inform' our database session
**  about the class, so that the session knows where to put the data that it's
**  going to grab from the database.
**
** \par Map the DBO class to the DBO Session
** \code
**  ...continued from the Session Connection string above
**  283   auto connection =
**  284     std::make_unique<Wt::Dbo::backend::MSSQLServer>( dbName );
**  285 #endif
**  286
**  287 #ifdef SHOW_QUERIES
**  288   connection-> setProperty( "show-queries", "true" );
**  289 #endif
**  290
**  291   setConnection( std::move( connection ) );
**  292
**  293   //
**  294   // map the 'Entity' class, and let the session know what the
**  295   //  actual table-name is
**  296   //
**  297   mapClass<Coy::Entity>("Entity");
** \endcode
**
**
** ### Create a Table View of the data
**
** We now have a session connection and we have a Class object mapped to that
**  session, now we can create a view to show the data.
**
** \par Create a Browser table-view of the data
** \code
**  348   {
**  349     // When talking to the database we need a transaction open
**  350     Wt::Dbo::Transaction t(*session());
**  351
**  352     // Ask the session to return a collection of 'entities'.  It's
**  353     //  just a vector, really, of a bunch of pointers to the entities.
**  354     //  It's pretty efficient and pretty fast.
**  355     auto entities = session()->
**  356       find<Coy::Entity>()
**  357       .where( "typeid = 5" )
**  358       .orderBy( "code desc" )
**  359       ;
**  360
**  361     // using the query from above, create a 'Model' of the data
**  362     auto queryModel = std::make_shared< Wt::Dbo::QueryModel< Wt::Dbo::ptr<Coy::Entity> > >();
**  363
**  364     queryModel-> setQuery( entities );
**  365     queryModel-> addColumn("id");
**  366     queryModel-> addColumn("code");
**  367     queryModel-> addColumn("description");
**  368     queryModel-> setColumnFlags( 2, Wt::ItemFlag::Editable );
**  369
**  370     // Create a TableView and assign the model to it
**  371     auto u_tableView = std::make_unique<Wt::WTableView>();
**  372     auto tableView = u_tableView.get();
**  373     lw-> addWidget( std::move(u_tableView) );
**  374     tableView-> setColumnWidth( 2, 600 );
**  375     tableView-> setAlternatingRowColors(true);
**  376     tableView-> setSelectionBehavior( Wt::SelectionBehavior::Items );
**  377     tableView-> setSelectionMode( Wt::SelectionMode::Single );
**  378     tableView-> setEditTriggers( Wt::EditTrigger::DoubleClicked );
**  379     tableView-> setEditOptions( Wt::EditOption::SingleEditor );
**  380
**  381     tableView-> setModel( queryModel );
**  382   }
** \endcode
**
** This should produce somthing like this;
**
** \image html wt-connects-to-mssql-tableview.png
**
** ### Conclusion
**
** As you can see, it's really quite easy to establish a connect to a remote database
**  even running on a foreign operating system, and build interfaces and classes to access
**  and manipulate that data.
**
** Wt is pretty powerful stuff.  You will be well advised to wear protection at all times
**  when working with it!
**
** - References
**  -# https://www.webtoolkit.eu/wt/doc/tutorial/dbo.html
**  -# https://redmine.webtoolkit.eu/boards/1/topics/15859
**  -# https://redmine.webtoolkit.eu/boards/1/topics/15841
**  -# https://docs.microsoft.com/en-us/sql/connect/odbc/linux-mac/installing-the-microsoft-odbc-driver-for-sql-server?view=sql-server-2017
**
*/

/*!
** \page create_database Create a new database or copy an existing database
**
** \code
**  //  sudo -u postgres psql -c 'create database test;'
**  //   'grant all privileges on database test to username;
**  //
**  // to copy a database in to another database;
**  //  1. close any open applications on the source database
**  //  2. execute the following as 'root' user;
**  //     a. serveradmin@lsus1:projects/warehouse$ sudo -u postgres psql
**  //     b. [sudo] password for serveradmin:
**  //     c. psql (9.5.19)
**  //     d. Type "help" for help.
**  //     e. postgres=# create database warehouse_1 with template warehouse;
**  //
**  //     this will copy in its entirety with all permissions the source database
**  //      to the destination database.
**  //
** \endcode
*/


/*!
** \page wkhtmltopdf Generating PDF with wkhtmltopdf
**
** This page discusses the steps necessary to take a document (aka; web-page) from
**  within Wt and convert it to a well-formatted, well-behaved PDF file. The value
**  of these techniques is high since Wt makes generating and manipulating HTML
**  pages quite easy, and when combined with some good HTML layout techniques,
**  it becomes possible to produce web-pages that look good in a browser as well
**  as a PDF file.
**
** Disclaimer: these techniques are my own, after much trial and error.  These
**  techniques are in no way to be confused with the "right way".  Use what you
**  can, your mileage may vary.
**
** Additional Disclaimer: Note that Wt includes some objects for manipulating PDF
**  files: https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WPdfImage.html
**  I have not taken the time to review these objects or attempt to employ them.
**  When I am able to I will and then produce a complimentary set of documents to match.
**
** Since we're talking about using wkhtmltopdf.org to generate a PDF document from
**  a HTML file, let's talk about specific use cases.  It's one thing to take any
**  simple webpage or website and run it through wkhtmltopdf and get a PDF file of
**  the same.  But, when it comes to generating things like "specifically formatted"
**  webpage, similar to those that might represent an 'invoice' or 'report' then
**  some tips and tricks and techniques are in order.  There are plenty of tutorials
**  available on the web for simple basic use cases.  This document is specific
**  to a "formatted result" outcome.
**
** <h3> Let's Begin </h3>
**
** \par Step 1 ~ Installation
** Get wkhtmltopdf installed.  I can't advise you on how to do that, it depends on
**  your platform.  You should be able to call upon wkhtmltopdf from the command
**  line like so;
**
** Calling wkhtmltopdf
** \code
**  mark@lsus1:~/projects/wt/Wtx$ wkhtmltopdf
**  You need to specify atleast one input file, and exactly one output file
**  Use - for stdin or stdout
**
**  Name:
**    wkhtmltopdf 0.12.2.4
** \endcode
**
**
** https://github.com/wkhtmltopdf/wkhtmltopdf/issues/2000
**
**
*/

/*!
** \page smtp_relay Setting up an SMTP relay for sending emails
**
**  https://pepipost.com/tutorials/configure-postfix-sendmail-using-external-server/
**
*/

/*!
** \page timezone Setting the proper TimeZone at application start-up
**
** In order to use Wt::WLocalDateTime, you must set in a proper time-zone
**  inside the application locale.  The following codes will aid in setting
**  the locale with a proper time-zone and perhaps custom date formatting
**  and so on.
**
** \code·
** 148   #include <chrono>
** 149   #include <Wt/Date/tz.h>
** 150
** 151   //
** 152   // set the time-zone to the proper format
** 154   //
** 155   auto loc = locale();
** 156
** 157   auto tz = date::locate_zone( environment().timeZoneName() );
** 158
** 159   loc.setTimeZone( tz );
** 160
** 161   std::cout << __FILE__ << ":" << __LINE__
** 162     << " tzn:" << environment().timeZoneName()
** 163     << " tzo:" << environment().timeZoneOffset().count()
** 164     << " tz:" << tz
** 165     << " loc:" << loc.name()
** 166     << " ltz:" << loc.timeZone()-> name()
** 167     << std::endl;
** 168
** 151   //
** 152   // set the date format to regular american
** 154   //
** 169   loc.setDateFormat( "MM/dd/yyyy" );
** 170   setLocale( loc );
** 171
** 172 } // endvoid MyProject::AppBase::init( )
** \endcode·
**·
**
*/

/*!
** \page apptic Application Tic
**
** If you want to have an external timer run on the application to give the
**  application a 'tic' that can be used to stimulate automatic actions within
**  the web page, there are a few methods.
**
** One method is to install a WTimer somewhere within the application and use
**  it to drive signal events.  The difficulty, however, with these timers is
**  that they place a load on both the web-browser and the network connection
**  as the WTimer is actually running within the web-browser, and must send
**  events back to the server through the network.  This can generate oddities
**  in the UI experience.
**
** Another method is to fire a separate thread that imposes a simple delay and
**  then calls-back in to the application to stimulate timer 'tic' events.
**
** \par Difference between thread timer and browser timer
** \code
**   Timer in Thread  Timer in Browser  Button in Browser
**   ---------------  ----------------  -----------------
**   thread           Browser           Browser
**   Timer (sleep)    Timer (sleep)     Button (click)
**   App (wake)       Network           Network
**   event()          Internet          Internet
**                    Network           Network
**                    Service           Service
**                    App (wake)        App (wake)
**                    event()           event()
** \endcode
**
** \code
190   std::thread thread( Rtm::AppBase::tic_handler, this );
191   thread.detach();
192
193 } // endvoid Rtm::AppBase::init( )
194
195 void Rtm::AppBase::tic_handler( Rtm::AppBase * app ) // this is a static function
196 {
197   /*
198   ** If there is no app-pointer, then quit.
199   **
200   */
201   if( !app )
202     return;
203
204   /*
205   ** This task just runs forever, sleeping for a bit, and then
206   **  waking the app.
207   **
208   */
209   while( true )
210   {
211     /*
212     ** Sleep this thread for just one second
213     **  before doing anything
214     **
215     */
216     std::this_thread::sleep_for( std::chrono::seconds(1) );
217
218     /*
219     ** If the application has already quit, then there's nothing to do.
220     **
221     */
222     if( app-> hasQuit() )
223       return;
224
225     /*
226     ** Acquire an application lock.  If the application is busy handling
227     **  some user interaction, this call will block until that other
228     **  task has completed.
229     **
230     */
231     Wt::WApplication::UpdateLock lock( app );
232
233     /*
234     ** If we could not get a lock, then quit.  If we could not get a lock,
235     **  then it sort of implies that the application was being destroyed.
236     **  In that case, we don't want to do anything more anyhow, so we just
237     **  quit.
238     **
239     */
240     if( !lock )
241       return;
242
243     /*
244     ** Make the tic happen
245     **
246     */
247     app-> tic();
248
249     /*
250     ** After everything has fired, trigger an update.
251     **
252     */
253     app-> triggerUpdate();
254
255   } // endwhile( true )
256
257 } // endvoid Rtm::AppBase::tic_handler( Rtm::AppBase * app )
258

2024 void AdminWidget::hold_me()
2025 {
2026   for( int i = 0; i < 10; i++ )
2027   {
2028     std::cout << __FILE__ << ":" << __LINE__ << " holding... " << i << std::endl;
2029
2030     std::this_thread::sleep_for( std::chrono::seconds(1) );
2031   }
2032
2033   std::cout << __FILE__ << ":" << __LINE__ << " held." << std::endl;
2034
2035 }
2036


AppBase.cpp:198 0
[2020-Jul-08 08:45:25.400] AppBase.cpp:298 logs/Admin(1)/2020-07-08.log Admin(1) buildSite logon ip:71.170.246.90 w:1920 h:1080
[2020-Jul-08 13:45:26.471] 26022 [/staff2 tg4JC7kUmbwSwunn] [warning] "WApplication: WApplication::addMetaHeader() with no effect"
AppBase.cpp:198 1
[2020-Jul-08 13:45:27.406] 26022 [/staff2 tg4JC7kUmbwSwunn] [error] "Wt: decodeSignal(): signal 'orp26iu.render' not exposed"
AppBase.cpp:198 2
AppBase.cpp:198 3
AppBase.cpp:198 4
AppBase.cpp:198 5
src/AppStaff.cpp:2028 holding... 0
src/AppStaff.cpp:2028 holding... 1
src/AppStaff.cpp:2028 holding... 2
src/AppStaff.cpp:2028 holding... 3
src/AppStaff.cpp:2028 holding... 4
src/AppStaff.cpp:2028 holding... 5
src/AppStaff.cpp:2028 holding... 6
src/AppStaff.cpp:2028 holding... 7
src/AppStaff.cpp:2028 holding... 8
src/AppStaff.cpp:2028 holding... 9
src/AppStaff.cpp:2033 held.
AppBase.cpp:198 6
AppBase.cpp:198 7
AppBase.cpp:198 8
AppBase.cpp:198 9
^Csleep for 1
** \endcode
**
*/



