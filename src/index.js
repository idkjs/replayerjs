import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import 'antd/dist/antd.css';
// import App from './App';
import App from './RecordPluginGuide.bs';
// import App from './Demo.bs';
// import App from './Task.bs';
import reportWebVitals from './reportWebVitals';
import events from "./events.json";
import * as rrweb from "rrweb";

const x = {
    "type":2,
    "tagName":"style",
    "attributes":{
        "data-nano-css-dev":""
    },
    "childNodes":[

    ],
    "id":75
};
const replayer = new rrweb.Replayer(x);

for (const event of events) {
    console.log(event)
  replayer.addEvent(event);
}
ReactDOM.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>,
  document.getElementById('root')
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
