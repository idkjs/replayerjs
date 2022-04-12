// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Css from "bs-css-emotion/src/Css.bs.js";
import * as Antd from "antd";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Rrweb from "rrweb";

function RecordPluginGuide$Button(Props) {
  var title = Props.title;
  var onClick = Props.onClick;
  return React.createElement(Antd.Button, {
              className: ".rr-block",
              onClick: onClick,
              children: title
            });
}

var Button = {
  make: RecordPluginGuide$Button
};

var exampleRecordPlugin = {
  name: "my-scope/example@1",
  observer: (function (cb, options) {
      var timer = setInterval((function (param) {
              return Curry._1(cb, {
                          foo: options.foo,
                          timestamp: Date.now()
                        });
            }), 1000);
      return function (param) {
        clearInterval(timer);
        
      };
    }),
  options: {
    foo: "bar"
  }
};

Curry._1(Rrweb.record({
          emit: (function ($$event) {
              console.log("emit", $$event);
              
            }),
          plugins: [exampleRecordPlugin]
        }), undefined);

function RecordPluginGuide(Props) {
  return React.createElement(Antd.Layout, {
              children: React.createElement(Antd.Layout.Header, {
                    children: React.createElement("span", {
                          className: Curry._1(Css.style, {
                                hd: Css.color(Css.white),
                                tl: /* [] */0
                              })
                        }, "RecordPlugin Example")
                  })
            });
}

var make = RecordPluginGuide;

var $$default = RecordPluginGuide;

export {
  Button ,
  exampleRecordPlugin ,
  make ,
  $$default ,
  $$default as default,
  
}
/*  Not a pure module */
