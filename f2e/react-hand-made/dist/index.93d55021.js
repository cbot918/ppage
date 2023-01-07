const log = console.log;
const React = {
    createElement: (tag, props, ...children)=>{
        if (typeof tag == "function") return tag(props);
        const element = {
            tag,
            props: {
                ...props,
                children
            }
        };
        log(element);
        return element;
    }
};
let states = [];
let stateIndex = 0;
const useState = (initialState)=>{
    const FREEZEINDEX = stateIndex;
    states[FREEZEINDEX] = states[FREEZEINDEX] || initialState;
    let setState = (newState)=>{
        log("hihi");
        states[FREEZEINDEX] = newState;
        rerender();
    };
    stateIndex += 1;
    return [
        states[FREEZEINDEX],
        setState
    ];
};
const App = ()=>{
    const [name, setName] = useState("yale");
    const [count, setCount] = useState(0);
    return /*#__PURE__*/ React.createElement("div", {
        __source: {
            fileName: "index.jsx",
            lineNumber: 34,
            columnNumber: 5
        },
        __self: this
    }, /*#__PURE__*/ React.createElement("h1", {
        __source: {
            fileName: "index.jsx",
            lineNumber: 35,
            columnNumber: 9
        },
        __self: this
    }, "name: ", name, " "), /*#__PURE__*/ React.createElement("input", {
        value: name,
        onchange: (e)=>{
            setName(e.target.value);
        },
        type: "text",
        placeholder: "test",
        __source: {
            fileName: "index.jsx",
            lineNumber: 36,
            columnNumber: 9
        },
        __self: this
    }), /*#__PURE__*/ React.createElement("h2", {
        __source: {
            fileName: "index.jsx",
            lineNumber: 42,
            columnNumber: 9
        },
        __self: this
    }, "count: ", count), /*#__PURE__*/ React.createElement("input", {
        onclick: ()=>setCount(count + 1),
        type: "button",
        value: "+",
        __source: {
            fileName: "index.jsx",
            lineNumber: 43,
            columnNumber: 9
        },
        __self: this
    }), /*#__PURE__*/ React.createElement("input", {
        onclick: ()=>setCount(count - 1),
        type: "button",
        value: "-",
        __source: {
            fileName: "index.jsx",
            lineNumber: 46,
            columnNumber: 9
        },
        __self: this
    }));
};
/*#__PURE__*/ React.createElement(App, {
    __source: {
        fileName: "index.jsx",
        lineNumber: 52,
        columnNumber: 1
    },
    __self: this
});
const render = (reactElementOrStringOrNumber, container)=>{
    let actualDomElement = document.createElement(reactElementOrStringOrNumber.tag);
    if ([
        "string",
        "number"
    ].includes(typeof reactElementOrStringOrNumber)) {
        container.appendChild(document.createTextNode(String(reactElementOrStringOrNumber)));
        return;
    }
    if (reactElementOrStringOrNumber.props) Object.keys(reactElementOrStringOrNumber.props).filter((p)=>p != "children").forEach((p)=>actualDomElement[p] = reactElementOrStringOrNumber.props[p]);
    if (reactElementOrStringOrNumber.props.children) reactElementOrStringOrNumber.props.children.forEach((child)=>render(child, actualDomElement));
    container.appendChild(actualDomElement, container);
};
const rerender = ()=>{
    stateIndex = 0;
    document.querySelector("#root").firstChild.remove();
    render(/*#__PURE__*/ React.createElement(App, {
        __source: {
            fileName: "index.jsx",
            lineNumber: 73,
            columnNumber: 12
        },
        __self: this
    }), document.querySelector("#root"));
};
render(/*#__PURE__*/ React.createElement(App, {
    __source: {
        fileName: "index.jsx",
        lineNumber: 76,
        columnNumber: 8
    },
    __self: this
}), document.querySelector("#root"));

//# sourceMappingURL=index.93d55021.js.map
