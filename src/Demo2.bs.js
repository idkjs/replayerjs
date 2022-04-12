// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Rrweb from "rrweb";

var events = [];

var stopFn1 = Rrweb.record({
      emit: (function (a) {
          events.push(a);
          console.log("events: ", events);
          console.log(a);
          
        })
    });

var stopFn2 = Rrweb.record({
      emit: (function (a) {
          events.push(a);
          console.log("events: ", events);
          console.log(a);
          
        }),
      ignoreClass: true
    });

Curry._1(stopFn1, undefined);

Curry._1(stopFn2, undefined);

var replayer = new Rrweb.Replayer(events);

console.log("replayer", replayer);

Curry._1(replayer.play, undefined);

function Demo2$default(Props) {
  return React.createElement("div", undefined, React.createElement("h1", undefined, "hello world and stuff yay"));
}

var $$default = Demo2$default;

export {
  events ,
  stopFn1 ,
  stopFn2 ,
  replayer ,
  $$default ,
  $$default as default,
  
}
/* stopFn1 Not a pure module */