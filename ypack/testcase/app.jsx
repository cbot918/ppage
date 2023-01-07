import * as React from 'react'
import * as Server from 'react-dom/server'
import Hello from './hello'

let Greet = () => <h1>Hello, world!</h1>
console.log(Server.renderToString(<Greet />))


import ReactDOM from 'react-dom/client'

const root = ReactDOM.createRoot(document.getElementById('root'))
root.render(
    <Hello />
)