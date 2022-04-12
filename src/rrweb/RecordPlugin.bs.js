// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";

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

export {
  exampleRecordPlugin ,
  
}
/* No side effect */
