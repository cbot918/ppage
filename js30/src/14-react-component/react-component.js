const log = console.log

const React = {
    createElement:(tag, props, ...children)=>{
        if (typeof tag == 'function'){
            return tag(props)
        }
        const element = {tag, props:{...props, children}}
        log(element)
        return element
    }
}

let states = []
let stateIndex = 0

const useState = (initialState)=>{
    const FREEZEINDEX = stateIndex
    states[FREEZEINDEX] = states[FREEZEINDEX] || initialState
    let setState = (newState)=>{
        log("hihi")
        states[FREEZEINDEX] = newState
        rerender()
    }
    stateIndex += 1
    return [states[FREEZEINDEX], setState]
}

const App =()=> {
    
    const [name, setName] = useState("yale")
    const [count, setCount] = useState(0)
    return (
    <div>
        <h1>name: {name} </h1>
        <input 
            value={name}
            onchange={e=>{
                setName(e.target.value)
            }}
            type="text" placeholder="test" />
        <h2>count: {count}</h2>
        <input 
            onclick={()=>setCount(count+1)}
            type="button" value="+" />
        <input 
            onclick={()=>setCount(count-1)}
            type="button" value="-" />
    </div>
)}

<App/>

const render = (reactElementOrStringOrNumber, container)=>{
    let actualDomElement = document.createElement(reactElementOrStringOrNumber.tag)
    
    if (['string','number'].includes(typeof reactElementOrStringOrNumber)){
        container.appendChild(document.createTextNode(String(reactElementOrStringOrNumber)))
        return
    }
    if (reactElementOrStringOrNumber.props){
        Object.keys(reactElementOrStringOrNumber.props).filter(p=>p!='children').forEach(p=>actualDomElement[p] = reactElementOrStringOrNumber.props[p])
    }
    if (reactElementOrStringOrNumber.props.children){
        reactElementOrStringOrNumber.props.children.forEach(child=>render(child, actualDomElement))
    }
    container.appendChild(actualDomElement, container)
}

const rerender = ()=>{
    stateIndex = 0
    document.querySelector("#root").firstChild.remove()
    render(<App/>, document.querySelector("#root"))
}

render(<App/>, document.querySelector("#root"))
