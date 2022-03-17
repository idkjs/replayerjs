import logo from './logo.svg';
import './App.css';
import * as rrweb from 'rrweb';

// const events = [];
// rrweb.record({
//     emit(event) {
//         events.push(event);
//         console.log(events, 'events');
//     },
// });

// const replayer = new rrweb.Replayer(events);
// let play = () => { console.log("running play"); replayer.play(); }
// play()

const events = [];
const stopFn = rrweb.record({
  emit(event) {
    events.push(event);
  },
});

// Interact with the page

stopFn();

var replayer = new rrweb.Replayer(events);

replayer.play();


function App() {
    return (
        <div className="App">
            <header className="App-header">
                <img src={logo} className="App-logo" alt="logo" />
                <p>
                    Edit <code>src/App.js</code> and save to reload.
                </p>
                <a
                    className="App-link"
                    href="https://reactjs.org"
                    target="_blank"
                    rel="noopener noreferrer"
                >
                    Learn React
                </a>
            </header>
        </div>
    );
}

export default App;
