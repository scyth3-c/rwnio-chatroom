


<div align="center">
   <img src="https://user-images.githubusercontent.com/52190352/168948479-74c41290-e4fb-499c-9d8f-34cbca8bf931.gif"></img>
</div>

 <div align="center"> 
   <img src="https://img.shields.io/static/v1?label=update&message=Today&color=success">
   <img src="https://img.shields.io/static/v1?label=version&message=0.9.0&color=green">
   <img src="https://img.shields.io/static/v1?label=lenguage&message=CPP&color=blue">
   <img src="https://img.shields.io/static/v1?label=standar&message=CPP17&color=red">
   <img src="https://img.shields.io/static/v1?label=CONTRIBUTIONS&message=ALL WELCOME&color=green">   
  
 </div>

<hr/>

<div align="center">

   <img width="200px"  src="https://user-images.githubusercontent.com/52190352/168956540-9654f48b-fe7e-4e2e-86da-a9df2db51086.png"/>
    <h1>rwnio</h1>
</div>



_rwnio is a program in terminal to talk in chat rooms with your friends, you can both create and join one, these rooms stay for a week and then disappear, if everyone leaves they can re-enter using the hash_

_you can set your name when you launch the program, as well as change it once inside, which is persistent locally on your computer, the only information you need is a nickname and it is optional, the messages become invisible after 2s of typing but STILL there to be sent, enjoy rwnio_


## contribution

any contribution is welcome, currently there are some necessary functionalities that are not yet implemented and I am working on it, your help would be awesome, any contribution, be sure to tell me what changes and what effect it will bring to rwnio.



## important

currently the api is in a free service that shuts down after 10min if the app is not used in general, it will take some time at startup

also, I haven't implemented the symmetric encryption of the messages yet, I am in process, in the future I will change the http system for websockets that I don't use at the moment because I want to make it a little bit raw and improve it.

_if when starting the room it seems that the same message is sent again, it is not so and it will be updated a second later_

## platforms

- linux (Ubuntu 22.04) and in process
- windows (coming soon)
- other (coming soon)


## to compile

```

 # sudo make install 
  
 # make
  
 # ./bin/rwnio
 
```

## Run and Arguments

```

# ./bin/rwnio <username>  <my_seed>      
or
#./bin/rwnio  <my_seed>              (your nick is default,change it in the menu)
or 
# ./bin/rwnio                        (your nick is default, change it in the menu)

```




## interesting

building in:  Ubuntu 22.04 

ssl is includes (this is in the makefile)

flags: -lcurl -lcrypto

``` 

I/opt/ssl/include/   

L/opt/ssl/lib/


```
