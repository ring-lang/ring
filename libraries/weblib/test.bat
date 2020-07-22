echo off
cls
set REQUEST_METHOD=GET
set QUERY_STRING=""
cd ringapp
ring index.ring 
cd ..
