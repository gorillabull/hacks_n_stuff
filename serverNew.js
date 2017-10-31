var http = require('http');
var url = require('url');
var fs = require('fs');

http.createServer(function (req, res) {
    var q = url.parse(req.url, true);
    var filename = q.pathname;
    //./ddd&something=val1&some2=val2
    console.log(filename);

    var tokens = filename.split("&");
    console.log(tokens);

    //----------------------------------------------------------Return Pow of passed data in url //----------------------------------------------------------
    if (tokens[0].includes("username")) {

        //ddd, username=val1, pw=val2
        var uName;
        var pW;
        var pwFinal;
        var uNameFinal;
        //resturantid=123&mitem1=23&mmitem2=23&mitem3=32&extra1=0&extra2=0
        if (tokens.length > 1) {
            uName = tokens[0].split("username=");
            //uNameFinal = val1;
            uNameFinal = uName[1];
        }
        if (tokens.length >= 2) {
            pW = tokens[1].split("pw=");
            //pwFinal = val2;
            pwFinal = pW[1];
        }

        var pwInt = parseInt(pwFinal);
        pwInt = Math.pow(pwInt, pwInt);

        console.log(uNameFinal + " final username");
        console.log(pwFinal + " final password");
        console.log("-----------------------------------");
        //var s = lookupUser(uNameFinal);

        //console.log(s.toString() + "ourvalue");

        /*	res.write(uNameFinal);
       res.write(pwFinal);
    if (filename.search("ddd") > 0) {
              res.writeHead(200, { 'Content-Type': 'text/html' });
               res.write('<form action="fileupload" method="post" enctype="multipart/form-data">');
               res.write('<input type="file" name="filetoupload"><br>');
               res.write('<input type="submit">');
               res.write('</form>');
               // res.write('<img src = "animeguylol.JPG" style="width:304px;height:228px;">')
       
    }
    */
        res.write(pwInt.toString());
        res.end();

    }
    for (var i = 0; i < tokens.length; i++) {
        if (tokens[i].includes("url3")) {
            res.write("<html>");
            res.write("<img src =  https://i.imgur.com/4IG8ITg.jpg>");
            res.write("");
            res.write("");
            res.write("");
            res.write("");
            res.write("");
            res.write("");
            res.write("</html>");
            res.write("<img src =  https://i.imgur.com/4IG8ITg.jpg>");
            res.end();
            break;
        }
    }
    //---------------------------------------------------------- TEXT //----------------------------------------------------------


    /*
    
    fs.writeFile('mynewfile3.txt', filename, function (err) {
     if (err) throw err;
     
   });
     fs.readFile(filename, function(err, data) {
       if (err) {
         res.writeHead(404, {'Content-Type': 'text/html'});
         return res.end("404 Not Found");
       }  
       res.writeHead(200, {'Content-Type': 'text/html'});
       res.write(data);
       return res.end();
     });
     */

}).listen(1337);