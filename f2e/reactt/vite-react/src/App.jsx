import { useState } from 'react'
import './App.scss'

function App() {

  return (
    <div className="p-2">
      <div className="flex flex-row justify-between">
        <div className="font-bold">縮指定網址服務</div>
        <input className="font-semibold cursor-pointer bg-slate-300 rounded-md text-sm" type="button" value="登入"/>
      </div>
      <br />
      <form>
          <div className="grid gap-6 mb-6 md:grid-cols-2">
              <div>
                  <label htmlFor="first_name" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">source url</label>
                  <input type="text" id="first_name" className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="input url" required/>
              </div>
              
              <div>
                  <label htmlFor="last_name" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">fixed url</label>
                  <div className="flex flex-row items-center">
                  <span>sheep.io/yale918/</span>
                  <input type="text" id="last_name" className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="input brief" required/>
                  </div>
                  
              </div>
          </div>
          
          <button type="submit" className="text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm w-full sm:w-auto px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Submit</button>
      </form>
    </div>
  )
}

export default App