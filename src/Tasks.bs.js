// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Css from "bs-css-emotion/src/Css.bs.js";
import * as Curry from "rescript/lib/es6/curry.js";
import * as React from "react";
import * as Rrweb from "rrweb";

var btn = Curry._1(Css.style, {
      hd: Css.display("flex"),
      tl: {
        hd: Css.alignItems("center"),
        tl: {
          hd: Css.justifyContent("center"),
          tl: {
            hd: Css.margin2("zero", "auto"),
            tl: /* [] */0
          }
        }
      }
    });

var Styles = {
  btn: btn
};

var events = [];

Curry._1(Rrweb.record, {
      emit: (function ($$event) {
          events.push($$event);
          console.log(events, "events");
          
        })
    });

function Tasks(Props) {
  return React.createElement("div", undefined, React.createElement("button", {
                  className: btn,
                  onClick: (function (param) {
                      return Curry._1(Rrweb.record, {
                                  emit: (function (param) {
                                      console.log("emmitting");
                                      
                                    })
                                });
                    })
                }, "Stop record"), React.createElement("button", {
                  className: btn,
                  onClick: (function (param) {
                      var replayer = Curry._1(Rrweb.Replayer, {
                            events: events
                          });
                      console.log("replayer:", replayer);
                      return Curry._1(replayer.play, undefined);
                    })
                }, "Replay"));
}

var make = Tasks;

var $$default = Tasks;

export {
  Styles ,
  events ,
  make ,
  $$default ,
  $$default as default,
  
}
/* btn Not a pure module */
